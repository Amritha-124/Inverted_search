

#include"main.h"
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>

//save database
int save_database(w_node **word,char *output)
{
    int i;
     
    if(strcmp(strstr(output,"."),".txt")!=0)
    {
	printf("%s is not a text file\n",output);
	return FAILURE;
    }
    FILE *fptr = fopen(output,"w"); 
    for(i=0;i<26;i++)
    {
	
	if(word[i]!=NULL)
	{
	    w_node *w_temp = word[i];
	   // fprintf(fptr,"#:%d:",i);
	    while(w_temp)
	    {
		fprintf(fptr,"#:%d:%s:%d",i,w_temp->w_name,w_temp->f_count);
		f_node *f_temp = w_temp->f_link;
                while(f_temp)
		{
		    fprintf(fptr,":%s:%d",f_temp->f_name,f_temp->w_count);
		    f_temp = f_temp->file_node_link;
		}
		fprintf(fptr,"#\n");

		w_temp = w_temp->w_link;
	    }


	}
    }
    return SUCCESS;
}

