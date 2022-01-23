#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}nod;
void push(nod ** head,int val){
    nod *temp=*head;
    nod *newnode=(nod *)malloc(sizeof(nod));
    newnode->data=val;
    if(*head==NULL){
        *head=newnode;
        (*head)->next=NULL;
    }
    else{
        newnode->next=*head;
        *head=newnode;
    }
}
void insert(nod **head,int val){
    nod *newnode=(nod *)malloc(sizeof(nod));
    nod *temp=*head;
    newnode->data=val;
    if(*head==NULL){
        *head=newnode;
        (*head)->next=NULL;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}
void pop(nod ** head){
    nod *temp=*head;
    if(*head==NULL){
        printf("Stack is empty\n");
    }
    else if((*head)->next==NULL){
        printf("Element deleted from stack is %d\n",temp->data);
        free(temp);
        *head=NULL;
    }
    else{
        *head=temp->next;
        printf("Element deleted from stack is %d\n",temp->data);
        free(temp);
    }
}
void del(nod **head){
    nod *temp=*head,*prev;
    if(*head==NULL){
        printf("Underflow , Queue is empty\n");
    }
    else if((*head)->next==NULL){
        printf("Element deleted from queue is %d\n",temp->data);
        free(temp);
        *head=NULL;
    }
    else{
        *head=temp->next;
        printf("Element deleted from queue is %d\n",temp->data);
        free(temp);
    }
}
void dispstk(nod *head){
    nod *temp=head;
    int i=1;
    if(head==NULL){
        printf("Stack is empty\n");
    }
    else{
        while(temp!=NULL){
            printf("%d element is %d\n",i,temp->data);
            i++;
            temp=temp->next;
        }
    }
}
void dispq(nod *head){
    nod *temp;
    int i=1;
    if(head==NULL){
        printf("Queue is empty\n");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("%d element is %d\n",i,temp->data);
            i++;
            temp=temp->next;
        }
    }
}
int main()
{
    nod *head=NULL;
    int choice,ic,value;
	printf("    *** MENU ***\n");
    printf("1.Stack implementation \n2.Queue implementation\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    if(choice==1){
        printf("1.Push \n2.Pop \n3.Display\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ic);
        while(ic!=4){
            switch(ic){
                case 1:
                    printf("Enter the element to be pushed : ");
                    scanf("%d",&value);
                    push(&head,value);
                    break;
                case 2:
                    pop(&head);
                    break;
                case 3:
                    dispstk(head);
                    break;
                default:
                    printf("Enter a valid choice \n");
                    break;
            }
            printf("Enter your choice : ");
            scanf("%d",&ic);
        }
    }
    else if(choice==2){
        printf("1.Insert \n2.Delete \n3.Display\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ic);
        while(ic!=4){
            switch(ic){
                case 1:
                    printf("Enter the element to be inserted : ");
                    scanf("%d",&value);
                    insert(&head,value);
                    break;
                case 2:
                    del(&head);
                    break;
                case 3:
                    dispq(head);
                    break;
                default:
                    printf("Enter a valid choice \n");
                    break;
            }
            printf("Enter your choice : ");
            scanf("%d",&ic);
        }
    }
	return 0;
}
