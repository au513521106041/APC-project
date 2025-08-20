#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#ifndef APC_H
#define APC_H
#define SUCCESS 1
#define FAILURE 0

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

int validation(char *argv[]);

char Operator(char *argv[]);

int comparison_1(Dlist *head1,Dlist *head2);

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR ,Dlist **tailR);

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

void print_list(Dlist *head);

int insert_last(Dlist **head, Dlist **tail, int data);

int create_list_from_string(char *num, Dlist **head, Dlist **tail);

int insert_first(Dlist **head, Dlist **tail, int data);

#endif
