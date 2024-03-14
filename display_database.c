#include"main.h"
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>

//Display database
void display_database(w_node **word)
{
    int i;
    printf("-----------------------------------------------------------\n");
    for(i=0;i<26;i++)
    {
	if(word[i] != NULL)
	{
	    w_node *w_temp = word[i];
	    while(w_temp)
	    {

		printf("[%d] [%s] %d file/s: File : ",i,w_temp->w_name,w_temp->f_count);
		f_node *f_temp = w_temp->f_link;
		while(f_temp)
		{
		    printf("%s:%d ",f_temp->f_name,f_temp->w_count);
		    f_temp = f_temp->file_node_link;
		}
		printf("\n");

		w_temp = w_temp->w_link;
	    }
	}

    }
    printf("---------------------------------------------------------------\n");
}


