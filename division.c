#include "apc.h"

// Function to check if the represented number is zero
int is_zero(Dlist *head)
{
    while (head)
    {
        if (head->data != 0)
            return 0;   // Number is not zero
        head = head->next;
    }
    return 1;           // Number is zero
}

// Function to copy a doubly linked list from src to dest
void copy_list(Dlist *src, Dlist **destHead, Dlist **destTail)
{
    while (src)
    {
        insert_last(destHead, destTail, src->data);
        src = src->next;
    }
}

// Division function: divides number represented by (head1, tail1)
// by number represented by (head2, tail2), stores quotient in (headR, tailR)
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *tempDividendNode = *head1;      // Pointer to traverse dividend
    Dlist *partialDividendHead = NULL;     // Partial dividend for current step
    Dlist *partialDividendTail = NULL;

    // Check for division by zero
    if (is_zero(*head2))
    {
        printf("Error: Division by zero is not allowed.\n");
        return FAILURE;
    }

    // Traverse each digit of the dividend from left to right
    while (tempDividendNode != NULL)
    {
        // Append next digit to the current partial dividend
        insert_last(&partialDividendHead, &partialDividendTail, tempDividendNode->data);

        // Remove leading zeros in partial dividend (except last digit if zero)
        while (partialDividendHead && partialDividendHead->data == 0 && partialDividendHead->next != NULL)
        {
            Dlist *toFree = partialDividendHead;
            partialDividendHead = partialDividendHead->next;
            partialDividendHead->prev = NULL;
            free(toFree);
        }

        int quotientDigit = 0;

        // While partial dividend is greater than or equal to divisor
        while (comparison_1(partialDividendHead, *head2) >= 0)
        {
            // Copy divisor to temporary list for subtraction
            Dlist *divisorCopyHead = NULL, *divisorCopyTail = NULL;
            copy_list(*head2, &divisorCopyHead, &divisorCopyTail);

            // Subtract divisor from partial dividend
            Dlist *subResultHead = NULL, *subResultTail = NULL;
            subtraction(&partialDividendHead, &partialDividendTail, &divisorCopyHead, &divisorCopyTail, &subResultHead, &subResultTail);

            // Free the old partial dividend list
            while (partialDividendHead)
            {
                Dlist *temp = partialDividendHead;
                partialDividendHead = partialDividendHead->next;
                free(temp);
            }

            // Update partial dividend to subtraction result
            partialDividendHead = subResultHead;
            partialDividendTail = subResultTail;

            quotientDigit++;  // Increment quotient digit for this step
        }

        // Append computed quotient digit to the result list
        insert_last(headR, tailR, quotientDigit);

        // Move to the next digit in the dividend
        tempDividendNode = tempDividendNode->next;
    }

    // Remove leading zeros from the final quotient result (except keep at least one digit)
    while (*headR && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *toFree = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(toFree);
    }

    return SUCCESS;
}
