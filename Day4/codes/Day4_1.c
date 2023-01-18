#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;

node_t *create_node(int data);
void add_node_at_first_position(int data);
void display_list(void);
void add_node_at_last_position(int data);
int count_nodes(void);
void add_node_at_specific_pos(int data, int pos);
void delete_node_at_first_pos( void  ); 
void delete_node_at_last_pos( void );

int main()
{
    // add_node_at_first_position(10);
    // add_node_at_first_position(20);
    // add_node_at_first_position(30);

    add_node_at_last_position(10);
    add_node_at_last_position(20);
    add_node_at_last_position(30);

    // 10->20->30
    int pos;
    display_list();
    int data;
    // while (1)
    // {
    //     //step-1: accept position from user
    //     printf("enter the position: ");
    //     scanf("%d", &pos);

    //     //step-2: validate position
    //     if (pos > 0 && pos <= count_nodes() + 1) //if pos is valid then loop gets break
    //         break;

    //     printf("invalid position !!!\n");
    // }
    // printf("Enter the data");
    // scanf("%d", &data);

    // add_node_at_specific_pos( data , pos ); 
    //delete_node_at_first_pos( ); 
    delete_node_at_last_pos( ); 
    display_list( ); 
    return 0;
}

node_t *create_node(int data)
{
    //1.Allocate the memory dynamically for the node

    node_t *temp = (node_t *)malloc(sizeof(node_t));
    // malloc( ) function allocates req bytes of memory from heap section
    // on Success it returns the starting address of dyn allocated block
    // on Failure it returns NULL

    if (temp == NULL)
    {
        printf("Malloc failed ");
        exit(1);
    }
    //initialize members of the node
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void display_list(void)
{
    // if list is not empty
    if (head != NULL)
    {
        // start traversal from first node
        node_t *trav = head;
        printf("List is : head ->");
        //traverse till the last node
        while (trav != NULL)
        {
            printf("%d->", trav->data);
            trav = trav->next;
            // move the pointer to next node
        }
        printf(" null \n");
    }
}

void delete_node_at_first_pos( void  )
{
        if(head!=NULL)
        {
               //if list contains only one node 
               if(head->next == NULL)
               {
                   free(head); // To avoid mem leakage 
                   head = NULL; // To avoid dangling pointer 
               } 
               else // if list contains more than one node  
               {
                    node_t *temp = head;     
                    head = head->next;  
                    free(temp);
                    temp = NULL; //To avoid dangling pointer 
               }

        }
        else 
            printf("List is empty");
}

void add_node_at_specific_pos(int data, int pos)
{
    if (pos == 1)
        add_node_at_first_position(data);
    else if (pos == count_nodes() + 1) // if pos is last
        add_node_at_last_position(data);
    else
    {
        //create the node
        node_t *newnode = create_node(data);
        //start the traversal from first node
        node_t *trav = head;
        int i = 1;
        while (i < pos - 1)
        {
            i++;
            trav = trav->next;
        }

        newnode->next = trav->next;
        trav->next = newnode;
    }
}
void delete_node_at_last_pos( void )
{
    //check list is not empty 
    if(head!=NULL)
    {
            if(head->next == NULL) // if list contains one node 
            {
                  free(head); 
                  head = NULL;   
            }
            else// if list contains more than one node  
            {
                //start the traversal from first node 
                node_t *trav = head; 
                //traverse till second last node 
                while(trav->next->next!=NULL)
                {
                    trav = trav->next; 
                }    
                free(trav->next); 
                trav->next = NULL; 
            }
    }
    else 
      printf("List is empty");

}

void add_node_at_first_position(int data)
{
    // create a new node
    node_t *newnode = create_node(data);

    // if linked list is empty
    if (head == NULL)
    {
        head = newnode;
    }
    else //  if linked list is not empty
    {
        newnode->next = head;
        head = newnode;
    }
}
//                                     5 
void delete_node_at_specific_pos( int pos )
{
     if(pos == 1)
        delete_node_at_first_pos( ); 
     if(pos == count_nodes( ) )//if pos is last 
        delete_node_at_last_pos( ); 
     else 
     {
         //start the traversal from first node 
         node_t *trav = head; 
         int i = 1; 
         while( i < pos - 1 )
         {
             i++; 
             trav = trav->next;
         }
         /*
                Homework 
         */
     }


}

void add_node_at_last_position(int data)
{
    //1. Create a node

    node_t *newnode = create_node(data);
    // if linked list is empty
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        node_t *trav = head;
        //traverse till last node
        while (trav->next != NULL)
        {
            trav = trav->next;
            //move the pointer to next node
        }
        trav->next = newnode;
    }
}

int count_nodes(void)
{
    int cnt = 0;

    //if list is not empty
    if (head != NULL)
    {
        //start traversal from the first node
        node_t *trav = head;
        //traverse the list till last node and increment the counter
        while (trav != NULL)
        {
            cnt++;
            trav = trav->next;
        }

        //return final count i.e. no. of nodes in a list
    }

    return cnt;
}

/*

void free_list(void)
{
    //till list not becomes empty
    while( head != NULL )
        delete_node_at_last_position();
        
        //delete_node_at_first_position();

    printf("list freed successfully ....\n");
}


*/