/*
Name : AMRITHA G
Date :
Description :
Sample Input :
Sample Output :
 */

#include"main.h"
#include<stddef.h>
#include<stdio.h>


int main(int argc,char **argv)
{
    struct wnode *word[26] = {NULL};
    file_list *head = NULL;
    int option;
    char choice;
    int flag = 0;
    do
    {
    printf("1.Create Database\n2.Display Database\n3.Search data in database\n4.Update Database\n5.Save in Database\n6.Exit\n");
    printf("Enter the choice: \n");
    
    
	scanf("%d",&option);
	switch(option)
	{
	    case 1:
		if(flag == 1)
		{
		if(status_read_and_validation_of_args(argv,&head)==SUCCESS )
		{
		    printf("INFO:Validation Successfull\n");
		}
		else
		{
		    printf("INFO:Validation FAILED\n");
		}
		if(status_create_database(word,head)==SUCCESS)
		    printf("INFO:DATABASE CREATED\n");
		else
		    printf("INFO:DATABASE CREATION FAILED\n");
		}
		else
		    printf("database creation faliled\n");
		break;
	    case 2:
		display_database(word);
		break;
	    case 3:
		char w_data[100];
		printf("Enter the word to search: \n");
		scanf("%s",w_data);
		search_database(word,w_data);
		break;
	    case 4:
		char file_name[50];
		printf("Enter the file name to update data:\n");
		scanf("%s",file_name);
		if(update_database(word,file_name,&head)==SUCCESS)
		{
		    flag = 1;
		    printf("INFO:UPDATE SUCCESSFULL\n");
		}
		else
		{
		    printf("INFO:UPDATE FAILED\n");
		}
		break;
	    case 5:
		char output[50];
		printf("Enter the file name to save database :\n");
		scanf("%s",output);
		if(save_database(word,output)==SUCCESS)
		{
		    printf("INFO:DATABASE SAVED\n");
		}
		else
		{
		  printf("please enter a valid file name\n");  
		}
                 break;
         case 6:
              return 0;
	  default:
	   printf("Enter a valid option\n");   
	}
	printf("\nWant to continue? press[Yy |nN ]\n");
	scanf(" %c",&choice);
        }while(choice == 'y' || choice == 'Y');
	   
    

    return 0;
}

