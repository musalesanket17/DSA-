/*
    Program to implement singly linear linked list operations:

================================================================================*/

#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef struct node
{
    int data;//4 bytes
    struct node *next;//4 bytes on 
}node_t;

typedef int bool_t;

//size of (type *) => 4 bytes on 32-bit compiler 
//sizeof(struct node) : 8 bytes = 32-bit compiler

//we are defining "head" pointer variable of type node_t globally - global access
node_t *head = NULL; //we have created an empty linked list

//declarations of linked list functionalities
node_t *create_node(int data);
int count_nodes(void);
void display_list(void);
void add_node_at_last_position(int data);
void add_node_at_first_position(int data);
void add_node_at_specific_position(int pos, int data);
bool_t delete_node_at_first_position(void);
bool_t delete_node_at_last_position(void);
bool_t delete_node_at_specific_position(int pos);
void free_list(void);


int menu(void)
{
    int choice;

    //display menu options
    printf("***** singly linear linked list ******\n");
    printf("0. exit\n");
    printf("1. add node into the list at last position\n");
    printf("2. add node into the list at first position\n");
    printf("3. add node into the list at specific position\n");
    printf("4. delete node from the list at first position\n");
    printf("5. delete node from the list at last position\n");
    printf("6. delete node from the list at specific position\n");
    printf("7. display the list\n");
    
    //accept choice from user
    printf("enter the choice : ");
    scanf("%d", &choice);

    //return user entered choice to the calling function
    return choice;
}

enum menu_options{ EXIT, ADDLAST, ADDFIRST, ADDATPOS, DELFIRST, DELLAST, DELATPOS, DISP };

//entry point function
int main(void)
{
    int pos;
    int data;

    while( 1 )
    {
        int choice = menu();
        switch (choice)
        {
        case EXIT :
            free_list(); 
            exit(0);

        case ADDLAST:
            printf("enter the data : ");
            scanf("%d", &data);
            add_node_at_last_position(data);
            printf("node having data part : %d is added into the list at last position\n", data);
            break;

        case ADDFIRST:
            printf("enter the data : ");
            scanf("%d", &data);
            add_node_at_first_position(data);
            printf("node having data part : %d is added into the list at first position\n", data);
            break;

        case ADDATPOS:
            while( 1 )
            {
                //step-1: accept position from user
                printf("enter the position : ");
                scanf("%d", &pos);

                //step-2: validate position
                //if pos in inbetween 1 to count_nodes + 1 => pos is valid
                if( pos >= 1 && pos <= count_nodes() +  1 )
                    break;//pos is valid

                printf("invalid position !!!\n");
            }
            printf("enter the data : ");
            scanf("%d", &data);
            add_node_at_specific_position(pos, data);
            printf("node having data part : %d is added into the list at position: %d\n", data, pos);
            break;

        case DELFIRST:
            if( delete_node_at_first_position() )
                printf("node which is at first position deleted\n");
            break;
        
        case DELLAST:
            if( delete_node_at_last_position() )
                printf("node which is at last position deleted\n");

            break;

        case DELATPOS:
            while( 1 )
            {
                //step-1: accept position from user
                printf("enter the position : ");
                scanf("%d", &pos);

                //step-2: validate position
                //if pos in inbetween 1 to count_nodes => pos is valid
                if( pos >= 1 && pos <= count_nodes() )
                    break;//pos is valid

                printf("invalid position !!!\n");
            }

            
            if( delete_node_at_specific_position(pos) )
                printf("node at position: %d is deleted\n", pos);

            break;
        
        case DISP:
            display_list();
            break;


        default:
            printf("invalid choice !!!\n");
            break;
        }//end of switch control block

    }//end of while loop

    return 0;
}

//definitions of linked list functionalities
node_t *create_node(int data)
{
    //step-1 : allocate memory dynamically for a node
    node_t *temp = (node_t *)malloc( sizeof(node_t) );
    /*
        malloc() function allocates requested bytes of memory from heap section and on success it returns
        starting addr of that dynamically allocated block which we need to typecast into required type 
        of pointer, whereas on failure malloc() function returns NULL 
    */
    if( temp == NULL )
    {
        printf("malloc() function failed !!!\n");
        exit(1);//program will be exited with exit status as 1 => erroneous termination
    }

    //dynamically memory got allocated for a node
    //setp-2: initialize members of node
    temp->data = data;
    temp->next = NULL;
    //step-3: return an addr of dynamically created node to the calling function
    return temp;
}

int count_nodes(void)
{
    int cnt = 0;
    
    //if list is not empty
    if( head != NULL )
    {
        //start traversal of the list from first node
        node_t *trav = head;
        //traverse the list till last node including it
        while( trav != NULL )
        {
            cnt++;
            trav = trav->next;
        }
    }

    return cnt;
}

void display_list(void)
{
    //if list is not empty
    if(head != NULL )
    {
        printf("list is : head -> ");
        //start traversal from first node
        node_t *trav = head;
        //traverse the list till last node including it
        while( trav != NULL )
        {
            printf(" %d -> ", trav->data);//visit data part of each node
            trav = trav->next;//move trav pointer towards its next node
        }
        printf(" null\n");
        printf("no. of nodes in a list are : %d\n", count_nodes() );
    }
    else{
        printf("list is empty !!!\n");
        printf("no. of nodes in a list are : %d\n", count_nodes() );
    }
}

void add_node_at_last_position(int data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty => attach newly created node to the head
    if( head == NULL )
    {
        //store an addr of newly created node into the head
        head = newnode;
    }else//step-3: if list is not empty
    {
        //traversal always starts from first node
        node_t *trav = head;
        //traverse the list till last node
        while( trav->next != NULL )
        {
            trav = trav->next;//move trav pointer towards its next node
        }
        /* attach newly created node to the last node i.e. store an addr of newly created node into
        next part of last node */
        trav->next = newnode;       
    }
}

void add_node_at_first_position(int data)
{
    //step-1: create a newnode
    node_t *newnode = create_node(data);

    //step-2: if list is empty => attach newly created node to the head
    if( head == NULL )
    {
        //store an addr of newly created node into the head
        head = newnode;
    }else//step-3: if list is not empty
    {
        //attach cur first node into the next part of newly created node
        newnode->next = head;
	    //attach newly created node to the head
	    head = newnode;
    }
}


void add_node_at_specific_position(int pos, int data)
{
    if( pos == 1 )//if pos is the first position
        add_node_at_first_position(data);
    else if( pos == count_nodes() + 1 )//if pos is the last position
        add_node_at_last_position(data);
    else{//if pos is in between position
        //create a newnode
        node_t *newnode = create_node(data);
        int i = 1;
        //start traversal from first node
        node_t *trav = head;
        //traverse the list till (pos-1)th node
        while( i < pos-1 ){
            i++;
            trav = trav->next;
        }

        //attach cur (pos)th node into the next part of newly created node
        newnode->next = trav->next;
        //attach nelwy created node into the next part of (pos-1)th node
        trav->next = newnode;
    }
}

void free_list(void)
{
    //till list not becomes empty
    while( head != NULL )
        delete_node_at_last_position();
        
        //delete_node_at_first_position();

    printf("list freed successfully ....\n");
}

bool_t delete_node_at_first_position(void)
{
    //step-1:  check list is not empty: if list is empty return false
    if( head == NULL )
    {
        printf("list is empty !!!\n");
        return false;
    }
    else//if( head != NULL )//step-2: if list is not empty then only we can delete node from list
    {
        //step-3: if list contains only one node
        if( head->next == NULL )
        {
            //delete the node and make head as NULL
            free(head);//free(1000);
            head = NULL;
        }
        else//step-4: list contains more than one nodes
        {
            //store an addr cur first node into temp which is to be deleted
            node_t *temp = head;
            //attach cur second node to the head
            head = head->next;
            //delete node
            free(temp);
            temp=NULL;		
        }
        return true;
    }
}

bool_t delete_node_at_last_position(void)
{
    //step-1:  check list is not empty: if list is empty return false
    if( head == NULL )
    {
        printf("list is empty !!!\n");
        return false;
    }
    else//if( head != NULL )//step-2: if list is not empty then only we can delete node from list
    {
        //step-3: if list contains only one node
        if( head->next == NULL )
        {
            //delete the node and make head as NULL
            free(head);//free(1000);
            head = NULL;
        }
        else//step-4: list contains more than one nodes
        {
            //start traversal of the list from first node
            node_t *trav = head;
            //traverse the list till second last node
            while( trav->next->next != NULL)
                trav = trav->next;

            //delete last node and make next part of cur second last node as NULL
            free(trav->next);//free(3000);
            trav->next = NULL;
        }
        return true;
    }
}

bool_t delete_node_at_specific_position(int pos)
{
    if( pos == 1 )//if pos is the first position
        return delete_node_at_first_position();
    else if( pos == count_nodes() )//if pos is the last position
        return delete_node_at_last_position();
    else{//if pos is in between position
        int i=1;
        node_t *temp = NULL;
        //start traversal of the list from first node
        node_t *trav = head;
        //traverse the list till (pos-1)the node
        while( i < pos-1 ){
            i++;
            trav = trav->next;//move trav towards its next node
        }
        //store an addr of a node into a temp which is to be deleted
        temp = trav->next;
        //attach cur (pos+1)th node into the next part of (pos-1)th node
        trav->next = trav->next->next;
        //delete the node
        free(temp);
        temp = NULL;
        return true;
    }
}















