#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 3 //restricts the size of the array to 3

int stk[MAX];
int top=-1;
void push(int value);
void pop();
void peek();
void display();

int main()
{
    int opt,val;
    printf("\n **** MENU ****");
    printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");
    printf("\nEnter your option to perform the operation : ");
    scanf("%d",&opt);
    do
    {
        switch(opt){
            case 1:
                printf("Enter the number to be pushed into the stack : ");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
        printf("\nEnter your option to perform the operation : ");
        scanf("%d",&opt);
    }
    while(opt!=5);
    return 0;
}
void push(int val){
    if(top==MAX-1) 
    {
        printf("STACK OVERFLOW");
    }
    else{
        stk[++top]=val;
    }
}
void pop(){
    if(top!=-1){
        printf("Element deleted from the stack is %d",stk[top--]);
    }
    else{
        printf("STACK UNDERFLOW");
    }
}
void peek(){
    if(top==-1){
        printf("STACK IS EMPTY");
    }
    else{
        printf("TOP = %d",stk[top]);
    }
}
void display(){
    int x,i;
    x=top;
    if(x!=-1){
        for (i=x;i>=0;i--){
            printf("%d\n",stk[i]);
        }
    }
    else{
        printf("STACK IS EMPTY");
    }
}
