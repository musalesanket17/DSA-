#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct
{
    int arr[SIZE];
    int front;
    int rear;
} queue_t;
void init_queue(queue_t *pq);
int is_queue_full(queue_t *pq);
void enqueue(queue_t *pq, int ele);
int is_queue_empty(queue_t *pq);
void display_queue(queue_t *pq);
int get_front(queue_t *pq);
void dequeue(queue_t *pq);

int menu(void)
{
    int choice;
    printf("=================\n");
    printf("Linear queue..\n");
    printf("0.Exit\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display Queue\n");

    printf("Enter the choice");
    scanf("%d", &choice);
    return choice;
}
enum menu_options
{
    EXIT,
    ENQUEUE,
    DEQUEUE,
    DISPLAY
};

int main()
{
    queue_t q;
    int ele;
    init_queue(&q);
    while (1)
    {
        int choice = menu();
        switch (choice)
        {
        case EXIT:
            exit(0);

        case ENQUEUE:
            //step1: check queue is not full
            if (!is_queue_full(&q)) //if queue is not full
            {
                printf("Enter the ele : ");
                scanf("%d", &ele);
                enqueue(&q, ele);
                printf("%d is inserted in queue...\n", ele);
                display_queue(&q);
            }
            else
                printf("Queue is full!!!!\n");
            break;

        case DEQUEUE:
            //step1: check queue is not empty
            if (!is_queue_empty(&q)) //if queue is not empty
            {
                ele = get_front(&q);
                dequeue(&q);
                printf("Deleted ele is : %d\n", ele);
                display_queue(&q);
            }
            else
                printf("queue is empty!!!\n");
            break;

        case DISPLAY:
            display_queue(&q);
            break;

        } //End of switch
    }     //End of while loop
    return 0;
}

void init_queue(queue_t *pq)
{
    pq->rear = -1;
    pq->front = -1;
}
void dequeue(queue_t *pq)
{
    //increment value of front by 1[i.e we are deleting ele]
    pq->front++;
}
int get_front(queue_t *pq)
{
    //return the value which is at front position
    return (pq->arr[pq->front]);
}

int is_queue_full(queue_t *pq)
{
    return (pq->rear == SIZE - 1);
}

void enqueue(queue_t *pq, int ele)
{
    //step2: incrment value of rear by 1
    pq->rear++;

    //step3:insert the element into the queue from rear end
    pq->arr[pq->rear] = ele;

    //step4:if(front == -1) then front = 0
    if (pq->front == -1)
        pq->front = 0;
}
int is_queue_empty(queue_t *pq)
{
    return (pq->rear == -1 || pq->front > pq->rear);
}

void display_queue(queue_t *pq)
{

    if (!is_queue_empty(pq))
    {
        int index;
        printf("Queue ele are :");
        for (index = pq->front; index <= pq->rear; index++)
        {
            printf("%4d", pq->arr[index]);
        }
        printf("\n");
    }
    else
        printf("Queue is empty!!!\n");
}
