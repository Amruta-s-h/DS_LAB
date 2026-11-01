#include<stdio.h>
#define MAX 10
int queue[MAX];
int f=-1,r=-1;
void enqueue(int data)
{
    if(r==MAX-1){
        printf("queue is full!");
        return;
    }
    if(f==-1){
        f=0;
    }
    r++;
    queue[r]=data;
}
int dequeue()
{
    if(f==-1||f>r){
        printf("queue is empty!");
        return -1;
    }
    int pop=queue[f];
    f++;
    if(f>r){
        f=-1;
        r=-1;
    }
    return pop;
}
void display()
{
    if(f==-1||f>r){
        printf("queue is empty!");

    }
    else{
        for(int i=f;i<=r;i++){
            printf("%d ",queue[i]);
        }
    }
}
int main()
{
   int choice,element;

    while(1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&element);
                enqueue(element);
                break;

            case 2:
                element=dequeue();

                if(element!=-1)
                    printf("Deleted element: %d\n",element);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;

}
