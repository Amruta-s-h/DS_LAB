
#include<stdio.h>
#define SIZE 5

int items[SIZE];
int front=-1,rear=-1;

int isFull()
{
    if((front==rear+1)||(front==0 && rear==SIZE-1))
        return 1;

    return 0;
}

int isEmpty()
{
    if(front==-1)
        return 1;

    return 0;
}

void enQueue(int element)
{
    if(isFull())
    {
        printf("Queue is full!\n");
    }
    else
    {
        if(front==-1)
            front=0;

        rear=(rear+1)%SIZE;
        items[rear]=element;

        printf("Inserted -> %d\n",element);
    }
}

int deQueue()
{
    int element;

    if(isEmpty())
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        element=items[front];

        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%SIZE;
        }

        printf("Deleted element -> %d\n",element);
        return element;
    }
}

void display()
{
    int i;

    if(isEmpty())
    {
        printf("Empty Queue\n");
    }
    else
    {
        printf("Front -> %d\n",front);

        for(i=front;i!=rear;i=(i+1)%SIZE)
        {
            printf("%d ",items[i]);
        }

        printf("%d ",items[i]);

        printf("\nRear -> %d\n",rear);
    }
}

int main()
{
    int choice,element;

    while(1)
    {
        printf("\n--- CIRCULAR QUEUE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&element);
                enQueue(element);
                break;

            case 2:
                deQueue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
