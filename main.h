#ifndef MAIN_H
#define MAIN_H
#define SUCCESS 0
#define FAILURE -1
#define WORD_SIZE 100
#define FILE_SIZE 20



//word node structure
typedef struct wnode
{
    int f_count;
    char w_name[WORD_SIZE];
    struct wnode*w_link;
    struct fnode *f_link;
}w_node;

//file node
typedef struct fnode
{
    int w_count;
    char f_name[FILE_SIZE];
    struct fnode* file_node_link;

}f_node;
//single linked list
typedef struct file 
{
    char f_name[FILE_SIZE];
    struct file * f_name_link;
}file_list;

//functions
//openfile


//read and validation
int status_read_and_validation_of_args(char **argv,file_list **head);

//create a new database
int status_create_database(w_node **word,file_list *head);

//display the database
void display_database(w_node **word);

//search a word in database
int search_database(w_node **word,char *w_data);
//save database
int save_database(w_node **word,char *output);

//update database
int update_database(w_node **word,char *file_name,file_list **head);



#endif

