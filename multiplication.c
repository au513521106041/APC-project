#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    // Check if either input list is empty
    if (!head1 || !head2 || !*head1 || !*head2)
        return FAILURE;

    Dlist *digitNode2 = *tail2;   // Start from the least significant digit of second number
    int zeroPadding = 0;          // Number of zeros to append corresponding to digit position 

    // Initialize the result list with 0
    insert_first(headR, tailR, 0);

    // Loop over each digit of the second number
    while (digitNode2)
    {
        int digit2 = digitNode2->data;
        int carry = 0;

        Dlist *digitNode1 = *tail1;  // Start from the least significant digit of first number
        Dlist *partialHead = NULL, *partialTail = NULL;  // Partial product list for this digit multiplication

        // Multiply current digit of second number by all digits of first number
        while (digitNode1)
        {
            int digit1 = digitNode1->data;
            int product = digit1 * digit2 + carry;
            carry = product / 10;

            // Insert the last digit of product at the front of partial product list
            insert_first(&partialHead, &partialTail, product % 10);

            digitNode1 = digitNode1->prev;
        }

        // If there's remaining carry after multiplication, insert it too
        if (carry > 0)
            insert_first(&partialHead, &partialTail, carry);

        // Add zeroPadding zeros at the end of the partial product
        for (int i = 0; i < zeroPadding; i++)
            insert_last(&partialHead, &partialTail, 0);

        // Prepare new list variables to store sum of result and partial product
        Dlist *sumHead = NULL, *sumTail = NULL;

        // Sum the current result list and the new partial product list
        addition(headR, tailR, &partialHead, &partialTail, &sumHead, &sumTail);

        // Free the old result list nodes
        while (*headR)
        {
            Dlist *temp = *headR;
            *headR = (*headR)->next;
            free(temp);
        }

        // Update result list head and tail with sum list
        *headR = sumHead;
        *tailR = sumTail;

        // Move to next digit of second number to multiply, increment zeroPadding for place value
        digitNode2 = digitNode2->prev;
        zeroPadding++;
    }

    // Remove leading zeros from the final result list if any (except keep one digit if the number is 0)
    while (*headR && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }

    return SUCCESS;
}
