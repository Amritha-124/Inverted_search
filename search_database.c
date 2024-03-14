#include"main.h"
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>


//search database
int search_database(w_node **word,char *w_data)
{
    char ch = toupper(w_data[0]);
    int i = ch % 65;
    if (word[i] !=NULL)
    {
	w_node *w_temp = word[i];
	printf("--------------------------------------------------------------------------\n");
	while(w_temp)
	{
	    if(strcmp(w_temp->w_name,w_data)==0)
	    {
		printf("word %s is present in %d file/s\n",w_data,w_temp->f_count);
		f_node *f_temp = w_temp->f_link;
		while(f_temp)
		{
		    printf("In file : %s %d time/s\n",f_temp->f_name,f_temp->w_count);
		    f_temp = f_temp->file_node_link;
		}
		printf("----------------------------------------------------------------------\n");
		return 0;
	    }
	    w_temp = w_temp->w_link;
	}
    }
    printf("INFO:WORD NOT FOUND\n");
    return 0;
}

