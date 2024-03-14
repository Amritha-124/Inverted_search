#include"main.h"
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>


//update database
int update_database(w_node **word,char *file_name,file_list **head)
{
   
   FILE *fptr = fopen(file_name,"r");
   size_t buff_size = 0;
   char *l_buff ;
   //l_buff = (char *)malloc(buff_size * sizeof(char));
   while(getline(&l_buff,&buff_size,fptr) != -1)
   {
       //printf("%s",l_buff);
   char *token;
   int t;
   token = strtok(l_buff,"#:");
   //printf("%s\n",token);
   t = atoi(token);
   w_node *w_new = malloc(sizeof(w_node));
   if(word[t]==NULL)
   {
       token= strtok(NULL,"#:");
       
      strcpy(w_new->w_name ,token);
     
	 token = strtok(NULL,"#:");
	 w_new->f_count=atoi(token);
         w_new->w_link = NULL;
         word[t] = w_new;
   }
    else
   {
       w_node *w_temp = word[t];
       while(w_temp->w_link)
       {
	   w_temp = w_temp->w_link;
       }
       //create node
       token = strtok(NULL,"#:");
       strcpy(w_new->w_name,token);
      
       token = strtok(NULL,"#:");
       w_new->f_count = atoi(token);
       w_new->w_link = NULL;
       w_temp->w_link = w_new;
       

   }
   
    f_node *f_prev = NULL;
    
   for(int i=1;i<=(w_new->f_count);i++)
   {
       f_node *f_new = malloc(sizeof(f_node));
       
     
     token = strtok(NULL,"#:");
     strcpy(f_new->f_name,token);
     
     if(*head == NULL)
         {
              //create node
              file_list *new = malloc(sizeof(file_list));
              //validate
              if( new == NULL)
              {
                  return FAILURE;
            }
              strcpy(new->f_name , token);
             new->f_name_link = NULL;
              *head = new;

         }

     else
          {
  
              file_list *temp = *head;
              file_list *prev=*head;
                  
  
              while(temp!=NULL)
              {
  
                  if(strcmp(temp->f_name,token)==0)
                  {
                      
                      
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
                  strcpy(new->f_name , token);
                 new->f_name_link = NULL;
  
                  prev->f_name_link = new;
              }
  
         }

     token = strtok(NULL,"#:");
      t = atoi(token);
      f_new->w_count = t;
     f_new->file_node_link = NULL;
     if(i==1)
     {
     w_new->f_link = f_new;
     }
    else
     {
	 
       f_prev->file_node_link = f_new;
     }

     f_prev = f_new;
    
   }

   
 }

   return SUCCESS;
}

