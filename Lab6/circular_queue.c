#include <stdio.h>
#include <stdlib.h>
#define size 10
int front=-1,rear=-1;
int Q[size];
int isFull(){
    if((front==0 && rear==size-1)|| front==rear+1) return 1;
    else return 0;
}
int isEmpty(){
    if(front == -1) return 1;
    else return 0;
}
void insert(int val){
    if(isFull()){
        printf("Queue is Full\n");
    }
    else{
        if(front==-1) front=0;
        rear=(rear+1)%size;
        Q[rear]= val;
        printf("Inserted element is %d\n",val);
    }
}
int delete(){
    int element;
    if(isEmpty()){
        printf("Queue is empty\n");
        return 0;
    }
    else{
        element = Q[front];
        if(front==rear){
            front =-1;rear=-1;
        }
        else{
            front=(front + 1)%size;
        }
    }
    printf("Deleted element is %d\n",element);
    return element;
}
void display(){
    int i;
    if(isEmpty()){
        printf("Queue is Empty\n");
    }
    else{
        printf("Front  ->  %d\n",front);
        printf("Items -> ");
        for(i =front;i!=rear;i=(i+1)%size){
            printf(" %d ,",Q[i]);
        }
        printf("%d",Q[i]);
        printf("\n Rear -> %d \n",rear);
    }
}
int main()
{
    int n,choice;
    printf("    *** MENU *** \n");
    printf(" 1.Insert \n 2.Delete \n 3.Display \n 4.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice != 4){
        switch(choice){
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d",&n);
                insert(n);
                break;
            case 2:
                printf("The element deleted from the queue is %d\n",delete());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Kindly enter correct choice\n");
                break;
        }
        printf("Enter your choice : ");
        scanf("%d",&choice);
    }
    return 0;
}
