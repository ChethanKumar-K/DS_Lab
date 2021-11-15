#include <stdio.h>
#include <stdlib.h>
#define size 5
int a[size];
//int front,rear;
//int front =-1,rear=-1;
int front=-1,rear=-1;
int Qempty(){
    if(front==-1 && rear==-1){
        return 1;
    }
    else return 0;
}
int Qfull(){
    if(rear==size-1){
        return 1;
    }
    else return 0;
}
void EnQ(int x){
    if(Qempty()){
        a[++rear]=x;
        front=0;
    }
    else if(Qfull()){
        printf("Queue is Full ,element cannot be inserted\n");
    }
    else{
        a[++rear]=x;
    }
}
void DeQ(){
    if(Qempty()){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        front=-1;
        rear=-1;
        printf("Queue is empty now,element deleted from the queue is %d\n",a[front]);
    }
    else{
        printf("Element deleted from the queue is %d\n",a[front]);
        front=front+1;
    }
}
void first(){
    if(Qempty()){printf("The queue is empty\n");}
    else{
        printf("The first element of the queue is %d\n",a[front]);
    }
}
void last(){
    if(Qempty()){printf("The queue is empty\n");}
    else{
        printf("The last element of the queue is %d\n",a[rear]);
    }
}
void display(){
    if(Qempty()){
        printf("The queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice,num;
	printf("    ***MENU***  \n");
    printf("1.Enqueue\n2.Dequeue\n3.Front element\n4.Rear element\n5.Display\n6.Exit\n");
    printf("Enter the choice of the operation to be performed : ");
    scanf("%d",&choice);
    while(choice!=6){
    switch(choice){
        case 1:
            printf("Enter the element to be inserted into the queue:");
            scanf("%d",&num);
            EnQ(num);
            break;
        case 2:
            DeQ();
            break;
        case 3:
            first();
            break;
        case 4:
            last();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
        default:
            printf("Please enter a valid choice\n");
    }
    printf("Enter the choice of the operation to be performed : ");
    scanf("%d",&choice);
    }
	return 0;
}
