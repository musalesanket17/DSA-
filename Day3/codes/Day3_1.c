#include<stdio.h> 
#include<stdlib.h> 

typedef struct node
{
    int data; 
    struct node *next;  
}node_t; 

node_t *head = NULL;
node_t* create_node( int data ); 
void add_node_at_first_position( int data ); 
void add_node_at_last_position( int data ); 
void display_list( void ); 
int main( )
{

    // add_node_at_first_position( 10 ); 
    // add_node_at_first_position( 20 ); 
    // add_node_at_first_position( 30 );
    //30->20->10   
    add_node_at_last_position(10); 
    add_node_at_last_position(20); 
    add_node_at_last_position(30); 
    //10->20->30  
    display_list( ); 
    return 0; 
}

node_t* create_node( int data )
{
    
    //allocating the memory dynamically for the node 
    //     int *ptr =(int*)malloc(sizeof(int))   

     node_t *temp=(node_t *)malloc(sizeof(node_t));
//malloc function allocates memory from the heap section 
//on success it returns the staring address of dynamically 
//allocated block 
//on failure it returns NULL 

     if(temp == NULL)
     {
         printf("Malloc failed"); 
         exit(1);
     }   
     //init the members of the node 
     temp->data = data; 
     temp->next = NULL;  
     
     return temp;
}

void add_node_at_first_position( int data )
{
     //1.Create the node
      node_t *newnode  = create_node(data);  
      if(head == NULL) // linked list is empty 
      {
               head = newnode;   
      } 
      else //if linked list is not empty 
      {
          newnode->next =head; 
          head = newnode;
      }
}

void add_node_at_last_position( int data )
{
    //1.Create the node 
    node_t *newnode = create_node(data);
    if(head == NULL) // linked list is empty 
    {
           head = newnode;   
    }
    else // if list is not empty  
    {
         node_t *trav = head;
         while(trav->next!=NULL)
         {
              trav = trav->next; 
         }   
         trav->next = newnode;  
    }
}

void display_list( void )
{
    //if linked list is not empty 
    if(head!=NULL)
    {
        //start the traversal from first node   
        node_t *trav = head; 
        //Traverse till last node 
        while(trav!=NULL)
        {
            printf("%d->",trav->data); 
            trav = trav->next;
        }
        printf("null\n");
    }
    else 
        printf("\nList is empty");
}