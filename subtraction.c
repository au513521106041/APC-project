
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	 int borrow=0,digit1=0,digit2=0;
    int negative=0,sum=0;

	 int cmp=comparison_1(*head1,*head2);
	 if(cmp==0)
	 {
		insert_first(headR,tailR,0);    //if the given value is 0 means it will store 0 linkedlist.so,this function is used  
		return SUCCESS;
	 }

     Dlist *temp1=(cmp>=0) ? *tail1 : *tail2;   //assigning the last value to use it
	 Dlist *temp2=(cmp>=0) ? *tail2 : *tail1;
     negative=(cmp<0);

     while(temp1 != NULL || temp2 != NULL)
	 {
		if(temp1 != NULL)
		{                             //first digit 
			digit1=temp1->data;
			temp1=temp1->prev;
		}
		else
		{
			digit1=0;
		}
        
		if(temp2 != NULL)
		{
			digit2=temp2->data;          ///second digit
			temp2=temp2->prev;
		}
		else
		{
			digit2=0;
		}

         digit1=digit1-borrow;     //here the any borrow value is founded means that value is subracted with first digit 
         
		 if(digit1<digit2)
		 {
			digit1=digit1+10;       //here checking the which dight is big,if digit2 is big means the borrow will be 1 and the digit first value is will be added to 10.
			borrow=1;
		 }
		 else
		 {
			borrow=0;
		 }

         sum=digit1-digit2;

		 if(insert_first(headR,tailR,sum)==FAILURE)   //the result value is added to linked list at insert first method
		 {
			return FAILURE;
		 }

	 }

		 while(*headR && (*headR)->data==0 && (*headR)->next != NULL)
		 {
			Dlist *t=*headR;
			*headR=(*headR)->next;                       //it removing the extra 0s in front of the number
			(*headR)->prev=NULL;
			free(t);
		 }

		 if(negative)                   //if the result is negative means print a negative symbol
		 {
			printf("-");
		 }
        print_list(*headR);
		return SUCCESS;
}

