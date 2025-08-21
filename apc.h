
#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*Addition function*/
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Subraction function*/
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Multiplication function*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*division function*/
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);

/*converting string to nodes*/
int create_list_from_string(char *str, Dlist **head, Dlist **tail);

/*Insert the output at first*/
int insert_first(Dlist **head,Dlist **tail,int data);

/*print the list*/
void print_list(Dlist *head);

/*insert at last*/
int insert_last(Dlist **head, Dlist **tail, int data);

/*comparision the given value which one is high*/
int comparison_1(Dlist *head1,Dlist *head2);

/*copying the one list to another list*/
void copy_list(Dlist *src, Dlist **destHead, Dlist **destTail);

/*checking the given argument is zero*/
int is_zero(Dlist *head);

#endif
