
#include "apc.h"


int validation(char *argv[])
{
    for(int i=0;argv[1][i] !='\0';i++)
	{
		if(!(isdigit(argv[1][i])))
		{
			printf("Enter only Digits\n");
             return FAILURE;
		}
	} 

   for(int i=0;argv[3][i] !='\0';i++)
	{
		if(!(isdigit(argv[3][i])))
		{
			printf("Enter only Digits\n");
             return FAILURE;
		}
	}
	return SUCCESS; 
}

char Operator(char *argv[])
{
    if(argv[2][1]!='\0')
	{
		printf("Enter only single operant \n");
		return '\0';
	}
	if((argv[2][0]=='+' || argv[2][0]=='-' || argv[2][0]=='x' || argv[2][0]=='/' || argv[2][0]=='%'))
	{
             return argv[2][0];
	}
	else
	{
              printf("Enter only the operator (+,-,*,/,%%)\n");
			  return '\0';
	}
}


int main(int argc,char *argv[])
{
     if(argc==4)
	 {
	       Dlist *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL, *headR=NULL ,*tailR=NULL;
	       char option,operator;
		   char ch=argv[2][0];
           
	      if (validation(argv) == FAILURE)
		  {
                   return FAILURE;
		  }

           char op=Operator(argv);
           if (op=='\0')
		   {
                return FAILURE;
		   }
		    create_list_from_string(argv[1], &head1, &tail1);
            create_list_from_string(argv[3], &head2, &tail2);

		switch (op)
		{
			case '+':
				if((addition(&head1,&tail1,&head2,&tail2,&headR,&tailR))==SUCCESS)
				{
					printf("%s + %s = ", argv[1], argv[3]);
					print_list(headR);
					printf("Addition SuccessFully Done\n");
				}
				else
				{
					printf("Addition failed\n");
				}
				break;

			case '-':	
				if (subtraction(&head1, &tail1, &head2, &tail2, &headR,&tailR) == SUCCESS)
				{
                      print_list(headR);
                      printf("Subtraction Successfully Done\n");	
				}
				else
				{
                    printf("Subtraction Failed\n");
				}
				break;

			case 'x':	
				if(multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR) == SUCCESS)
			    {
				    printf("%s x %s = ", argv[1], argv[3]);
					print_list(headR);
					 printf("Multiplication successfully done\n");
			    }
			    else
			    {
			     	printf("Multiplication failed\n");
		        }
				break;

			case '/':	
			
				if (division(&head1,&tail1,&head2,&tail2,&headR,&tailR) == SUCCESS)
				{
                    printf("%s / %s = ", argv[1], argv[3]);
                    print_list(headR);
                    printf("Division Successfully Done\n");

				}
                else
				{
                    printf("Division Failed\n");
				}
				break;

			default:
				printf("Invalid Input:-( Try again...\n");
		}  
	 }
	 else
	 {
		printf("Enter <operant1> <operator> <operant2> like this\n");
		return FAILURE;
	 }

	return 0;
}
