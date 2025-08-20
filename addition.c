
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int digit1, digit2, sum, carry = 0, result;

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        // Get digit from list 1
        if (temp1 != NULL)
        {
            digit1 = temp1->data;
            temp1 = temp1->prev;
        } 
        else 
        {
            digit1 = 0;
        }

        // Get digit from list 2
        if (temp2 != NULL) 
        {
            digit2 = temp2->data;
            temp2 = temp2->prev;
        } 
        else 
        {
            digit2 = 0;
        }

        // Sum and carry
        sum = digit1 + digit2 + carry;
        result = sum % 10;
        carry = sum / 10;

        // Insert result at the front
        if (insert_first(headR, tailR, result) != SUCCESS) {
            return FAILURE;
        }
    }

    print_list(*headR);
    return SUCCESS;
}

