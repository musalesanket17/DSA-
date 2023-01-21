Result: Fail
Marks: 15/30
Percentage: 33.33 %
Questions: 10
Correct Answers: 5
Attempted: 10



1. what is wrong about singly linked list?

       1. Singly linked list is a collection of nodes linked together in a sequential way where each node of singly linked list contains a data field
       2. singly list is an address field which contains the reference of the next node.
       3. Singly linked list can contain multiple data fields but should contain at least single address field pointing to its connected next node.
    T->4. None Of Above




2. What would be the asymptotic time complexity to add a node at the end of singly linked list, if the pointer is initially pointing to the head of the list?

      1. O(1)
      2. O(n)
   T->3. θ(n)
      4. Θ(1)


3. which statement is True about circular linked list?

     1. Entire list can be traversed from any node.
     2. Circular lists are the required data structure when we want a list to be accessed in a circle or loop.
     3. Despite of being singly circular linked list we can easily traverse to its previous node, which is not possible in singly linked list.
   T->4. All of Above


4. What is the worst case time complexity of inserting a node in a doubly linked list?


     1. O(nlogn)
     2. O(logn)
   T->3. O(n)
     4. O(1)


5. Which of the following is false about a doubly linked list?

     1. We can navigate in both the directions
     2. It requires more space than a singly linked list
     3. The insertion and deletion of a node take a bit longer
   T->4. Implementing a doubly linked list is easier than singly linked list


6. Which of the following operations is performed more efficiently by doubly linked list than by singly linked list?

    T->1. Deleting a node whose location in given
      2. Searching of an unsorted list for a given item
      3. Inverting a node after the node with given location
      4. Traversing a list to process each node


7. What is the output of the following code for start pointing to first node of the given list? 1->2->3->4->5->6
 void Linkedlist(struct node* start)
{
if(start == NULL)
       return;
printf("%d",start->data);

if(start->next != NULL)
  Linkedlist(start->next->next);
printf("%d",start->data);
}

     1. 1 4 6 6 4 1
     2. 1 3 5 1 3 5
     3. 1 2 3 5
  T->4. 1 3 5 5 3 1




8. Which of the following data structure/s requires extra space to store n no. of elements?


     1. Array
     2. Structure
   T->3. LinkedList
     4. Union


9. Which of these is an application of linked lists?

      1. To implement file systems
      2. For separate chaining in hash-tables
      3. To implement non-binary trees
   T->4. All of the mentioned


10. what does following function do of given Linked List with first node as head?
void function(struct node* head)
{
  if(head == NULL)
    Return;
  
  function(head->next);
  printf("%d  ", head->data);
}

      1. Print all linked lists
  T-> 2. Prints all linked list in reverse order
      3. Prints alternate Linked List
      4. Prints alternate linked list reverse order