#include "apc.h"
int create_list_from_string(char *num, Dlist **head, Dlist **tail)
{
    for(int i=0;num[i]!='\0';i++)
    {
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL)
    {
        return FAILURE;
    }
    new->data =num[i]-'0';
    new->prev =NULL;
    new->next =NULL;
    
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
    }
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
    }   
    return SUCCESS;
}



int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    //IF LIST IS EMPTY
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
        return SUCCESS;
    }
    //IF LIST IS NOT EMPTY
    new->next=*head;
    (*head)->prev=new;
    *head=new;
    return SUCCESS;
   
}

int comparison_1(Dlist *head1,Dlist *head2)
{
     int len1=0,len2=0;
	 Dlist *temp1=head1;
	 Dlist *temp2=head2;

	 while(temp1 != NULL)    //finding the given string length
	 {
		len1++;
		temp1=temp1->next;
	 }
	 while (temp2 != NULL)
	 {
		 len2++;
		 temp2=temp2->next;
	 }

	 if(len1>len2)    //here which one is greater length
	 {
		return 1;
	 }
	 if(len2>len1)
	 {
		return -1;
	 }

     while(head1 && head2)
	 {                                      //comparing the data which one is greater 
		if(head1->data > head2->data)
		{
              return 1;
		}

		if(head2->data >head1->data)          
		{
			return -1;
		}
        head1=head1->next;
		head2=head2->next;
	 }
    return 0;
	 
}


int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (!new) return FAILURE;  // check malloc success

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail)
        (*tail)->next = new;
    else
        *head = new;

    *tail = new;
    return SUCCESS;
}


void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Head -> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d <-", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }
}