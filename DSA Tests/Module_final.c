Result: Pass
Marks: 42/60
Percentage: 60.00 %
Questions: 20
Correct Answers: 14
Attempted: 20



1. .___________________ are those structures that have one or more pointers which point to the same type of structure, as their member.


       T-> 1. Self Referential structures
           2. Circulre structures
           3. Data structures
           4. Pointer structures



2. Consider the following operation performed on a stack of size 7.
Push(22);
Push(23);
Push(33);
Pop();
Pop();
Push(62);
Pop();
Push(41);
Pop();
Pop();
Push(43);
Push(44);
Pop();
Push(6);
Pop();
After the completion of all operation, the no. of element present on stack are _________.


       T->1. 1
          2. 2
          3. 3
          4. 4



3. Evaluate Postfix expression from given infix expression.
A + B * (C + D) / (F + D) * E


       1. ABCD+*/F+DE*
       2. AB+CD*F/+D*E
    T->3. ABCD+*FD+/E*+
       4. ABCD+*FD+E*/+



4. The prefix form of an infix expression p+q-r*t is?



        1. + pq - *rt
        2. - +pqr * t
    T-> 3. - +pq * rt
        4. - + * pqrt



5. The difference between stacks and queues is in ______________________.


      T->1. removing elements
         2. adding elements at first position
         3. inserting elements at given position
         4. removing elements from given position




6. Which of the following is/are not the advantages of Linked List over an array?


      1-The size of a linked list can be incremented at runtime which is impossible in the case of the array.
      
      2-The List is not required to be contiguously present in the main memory, if the contiguous space is not available, the nodes can be stored anywhere in the memory connected through the links.
      
      3-The number of elements in the linked list are limited to the available memory space while the number of elements in the array is limited to the size of an array.





              1. 1,2
              2. 1
              3. 1,2,3
           T->4. none of above






7. The data structure required to evaluate a postfix expression is _________.

           1. queue
        T->2. stack
           3. array
           4. linked-list

8. What would be solution to given postfix notation: 2 3 1 * + 9 -  .

           1. 4
        T->2. -4
           3. 3
           4. -3




9. How do you count the number of elements in the circular linked list?.



          1. int count(struct node *head) {     int total = 0;     struct node *current = head;     do {         current = current->next;         total++;     } while (current != NULL);     return total; }
      T-> 2. int count(struct node *head) {     int total = 0;     struct node *current = head;     do {         current = current->next;         total++;     } while (current != head);     return total; }
          3. int count(struct node *head) {     int total = 0;     struct node *current = head;     do {         current = current->next;         total++;     } while (current != head && temp != null);     return total; }
          4. int count(struct node *head) {     int total = 0;     struct node *current = head;     do {         current = curr






10. what does the following function do for a given linked list with with first node as head?
void function(struct node* head) 
{
	if(head == NULL) 
		return; 
	function(head -> next); 
	printf("%d", head-> data); 
}




         1. prints alternate node of linked list
         2. prints alternate nodes in reverse order
         3. prints only even places nodes values
      T->4. prints all nodes of linked list in reverse order



11. In __________________ search start at the beginning of the list and check every element in the list.







          1. Binary search
       T->2. Linear search
          3. Hash Search
          4. Binary Tree search





12. A ________ node is a special node that is found at the beginning of the linked list.



            1. main
        T-> 2. header
            3. start
            4. beginer





13. In _____________ type of expression  operator succeeds its operands.


            1. Infix
            2. prefix
         T->3. postfix
            4. transfix



14. Write a suitable line instead of /*******************/
void deleteList(struct node* head)
{
   struct node* tmp;
   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       /**********************/
    }
}


        1. release(tmp)
      T->2. free(tmp);
        3. create(tmp)
        4. insert(tmp)


15. What is the time complexity of searching for an element in a circular linked list?



       T->1. O(n)
          2. O(1)
          3. O(n log n)
          4. O(n log (n-1))





16. What is the functionality of the following piece of code?
public int function(int data)
{
	Node temp = head;
	int var = 0;
	while(temp != null)
	{
		if(temp.getData() == data)
		{
			return var;
		}
		var = var+1;
		temp = temp.getNext();
	}
	return 0;
}


             1. Find and delete a given element in the list.
         T-> 2. Find and return the position of the given element in the list.
             3. Find and return the given element in the list.
             4. Find and return the given element in the list.


17. The balance Factor of a node in a binary tree is ?



           1. Addition of left subtree and rigth subtree.
           2. Height of right subtrees plus its subtrees.
        T->3. Height of left subtree minus height of right subtree.
           4. Addition of all nodes.


18. The preorder traversal sequence of a binary search tree is 29, 18, 10, 15, 23, 21, 37, 35, 45. Which one of the following is the postorder traversal sequence of the same tree?



           1. 10, 18, 15, 21, 23, 35, 45, 37, 29
           2. 15, 10, 23, 21, 18, 45, 35, 37, 29
           3. 15, 18, 10, 21, 23, 45, 35, 37, 29
        T->4. 15, 10, 21, 23, 18, 35, 45, 37, 29




19. Which of the following statements is not true about Singly circular linked list?


       T->1. Time complexity to searching an element is o(1).
          2. Every node in circular is successor.
          3. Time complexity to inserting new node at the head in list is o(n).
          4. Time complexity to deleting the last node is o(n).
          


20. .Which of the following is/are not correct.
Doubly circular linked list contains only one node, if _______________.
i-next part of first node contains address of last node
ii-next part of first node contains address of first node  
iii-prev part of last node contains null value
iv-prev part of last node contains address of first node



           1. i,iv
        T->2. iii
           3. i
           4. ii