#include "apc.h"

/* Easy-to-understand long multiplication for linked list big integers */
int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR)
{
    // Step 1: Shortcut if either number is zero
    if ((*head1)->data == 0 && (*head1)->next == NULL) {
        insert_first(headR, tailR, 0);
        print_list(*headR);
        return SUCCESS;
    }
    if ((*head2)->data == 0 && (*head2)->next == NULL) {
        insert_first(headR, tailR, 0);
        print_list(*headR);
        return SUCCESS;
    }

    // Step 2: Start with an empty result
    *headR = NULL;
    *tailR = NULL;

    int shift = 0;                  // How many zeros to add for place value
    Dlist *ptr2 = *tail2;           // Start from LSB of multiplier

    // Step 3: Outer loop — each digit of multiplier
    while (ptr2 != NULL) {
        int d2 = ptr2->data;        // Current multiplier digit
        int carry = 0;

        // Partial product list
        Dlist *pH = NULL, *pT = NULL;

        // Step 3a: Add shift zeros at the END (LS side)
        for (int i = 0; i < shift; i++) {
            insert_last(&pH, &pT, 0);
        }

        // Step 3b: Multiply with all digits of multiplicand
        Dlist *ptr1 = *tail1;       // Start from LSB of multiplicand
        while (ptr1 != NULL) {
            int prod = (ptr1->data * d2) + carry;
            int digit = prod % 10;
            carry = prod / 10;

            insert_first(&pH, &pT, digit);
            ptr1 = ptr1->prev;
        }

        // Step 3c: Leftover carry
        if (carry > 0)
            insert_first(&pH, &pT, carry);

        // Step 4: Add partial product to running total
        if (*headR == NULL) {
            // If result empty, use partial product directly
            *headR = pH;
            *tailR = pT;
        } else {
            addition(headR, tailR, &pH, &pT, NULL, NULL);

            // Free partial product as it’s no longer needed
            while (pH) {
                Dlist *tmp = pH;
                pH = pH->next;
                free(tmp);
            }
        }

        // Step 5: Shift will be bigger for next multiplier digit
        shift++;
        ptr2 = ptr2->prev;
    }

    // Step 6: Print result
    print_list(*headR);
    return SUCCESS;
}
