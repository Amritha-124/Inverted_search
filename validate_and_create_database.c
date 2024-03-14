#include"main.h"
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>



int status_read_and_validation_of_args(char **argv,file_list **head)
{
    int i=1;

    while(argv[i]!=NULL)
    {

        if(strcmp(strstr(argv[i],"."),".txt")!=0)
	{
           printf("INFO:%s is NOT A TEXT FILE\n",argv[i]);
	   break;    
		
	}
	

	if(*head == NULL)
	{
	    //create node
	    file_list *new = malloc(sizeof(file_list));
	    //validate
	    if( new == NULL)
	    {
		return FAILURE;
	    }
	    strcpy(new->f_name , argv[i]);
	    new->f_name_link = NULL;
	    *head = new;

	}
	else
	{

	    file_list *temp = *head;
	    file_list *prev=*head;
    	    	

	    while(temp!=NULL)
	    {

		if(strcmp(temp->f_name,argv[i])==0)
		{
                    
		    printf("INFO:DUPLICATE FOUND\n");
		    break;

		}
		
	       
	
		prev = temp;
		temp = temp->f_name_link;
	    }
	    if(temp == NULL)
	    {

		//create node
		file_list *new = malloc(sizeof(file_list));
		//validate
		if( new == NULL)
		{
		    return FAILURE;
		}
		strcpy(new->f_name , argv[i]);
		new->f_name_link = NULL;

		prev->f_name_link = new;
	    }

	}
	
	i++;
    }

    return SUCCESS;

}

//create database

int status_create_database(w_node **word,file_list *head)
{
    
    file_list *temp=head;

    while(temp!=NULL)
    {

	FILE *fptr = fopen(temp->f_name,"r");
	
	if(fptr==NULL)
	{
	    printf("INFO:FILE %s is DOESNT EXIST\n",temp->f_name);
	    
	}
	else
	{
	fseek(fptr,0,SEEK_END);
	if(ftell(fptr)==0)
	{
	    printf("INFO:FILE %s IS EMPTY\n",temp->f_name);
	    
	}
	else
	{
	rewind(fptr);
	char buff[100];
	while(fscanf(fptr,"%s",buff) != -1)
	{


	    char ch = toupper(buff[0]);
	    int index = ch % 65;
	    if(word[index] == NULL)
	    {

		//create word node
		w_node *w_new = malloc(sizeof(w_node));
		//validation
		if(w_new == NULL)
		{
		    return FAILURE;
		}
		w_new->f_count = 1;
		strcpy(w_new->w_name,buff);
		w_new->w_link=NULL;
		word[index] = w_new;
		//create file node
		f_node *f_new = malloc(sizeof(f_node));
		//validation
		if(f_new==NULL)
		{
		    return FAILURE;
		}
		f_new->w_count = 1;
		strcpy(f_new->f_name,temp->f_name);
		f_new->file_node_link = NULL;
		w_new->f_link = f_new;

	    }
	    else
	    {

		w_node *w_temp=word[index];
		w_node *w_prev = NULL;
		while(w_temp!=NULL)
		{
		    if(strcmp(w_temp->w_name,buff)==0)
		    {

			f_node *f_temp = w_temp->f_link;
			f_node *f_prev = w_temp->f_link;
			while(f_temp!=NULL)
			{
			    if(strcmp(temp->f_name,f_temp->f_name)==0)
			    {
				//update word count
				f_temp->w_count = f_temp->w_count + 1;

				break;
			    }
			    f_prev = f_temp;
			    f_temp = f_temp->file_node_link;

			}

			if(f_temp == NULL)
			{

                             
			    //create a f_node
			    f_node *f_new = malloc(sizeof(f_node));
			    //validating
			    if(f_new == NULL)
				return FAILURE;
			    f_new->w_count = 1;
			    strcpy(f_new->f_name,temp->f_name);
			    f_new->file_node_link = NULL;
			    f_prev->file_node_link = f_new;
			    w_temp->f_count = w_temp->f_count + 1;
			    

			}
			break;
		    }
		    w_prev = w_temp;
		    w_temp = w_temp->w_link;

		}
		if(w_temp == NULL)
		{
		  
		    //create w_node
		    w_node *w_new = malloc(sizeof(w_node));
		    //validating
		    if(w_new == NULL)
			return FAILURE;
		    w_new->f_count = 1;
		    strcpy(w_new->w_name,buff);
		    w_new->w_link=NULL;
		    w_prev->w_link = w_new;
		    //create file node
		    f_node *f_new = malloc(sizeof(f_node));
		    //validation
		    if(f_new==NULL)
		    {
			return FAILURE;
		    }
		    f_new->w_count = 1;
		    strcpy(f_new->f_name,temp->f_name);
		    f_new->file_node_link = NULL;
		    w_new->f_link = f_new;


		}

	    }

	}
	}
	}
	temp = temp->f_name_link;
    }
    return SUCCESS;
}



























