#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}nod;
nod *head=NULL;
void insert(int val){
    nod *temp,*newnode;
    newnode=(nod*)malloc(sizeof(nod));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        head->next=NULL;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}
void pop(){
    nod *temp;
    if(head==NULL){
        printf("The List is empty \n");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        head=head->next;
        printf("Element deleted from list : %d\n",temp->data);
        free(temp);
    }
}
void delete(){
    nod *temp,*prev;
    if(head==NULL){
        printf("The List is empty \n");
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        printf("Element deleted from list : %d\n",temp->data);
        free(temp);
    }
}
void delpos(int pos){
    nod *temp,*prev;
    if(pos==1){
        pop();
    }
    else{
        temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            printf("Entered position is invalid\n");
        }
        else if(temp->next->next==NULL){
            prev=temp;
            temp=temp->next;
            printf("Element deleted from the list is %d\n",temp->data);
            free(temp);
            prev->next=NULL;
        }
        else{
            printf("Element deleted from the list is %d\n",temp->next->data);
            prev=temp->next;
            temp->next=temp->next->next;
            free(prev);
        }
    }
}
void display(){
    nod *temp;
    int i=1;
    if(head==NULL){
        printf("The list is empty\n");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("Element at position %d is %d\n",i,temp->data);
            i++;
            temp=temp->next;
        }
    }    
}
int main()
{
    int pos,choice,num;
    printf("  ***   MENU    ***\n");
    printf("1.Insert\n2.Pop\n3.Delete\n4.Delete at position\n5.Display\n6.Exit\n");
    printf("Enter your choice of operation : ");
    scanf("%d",&choice);
    while(choice!=6){
        switch(choice){
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d",&num);
                insert(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                delete();
                break;
            case 4:
                printf("Enter the position at which node is to be deleted : ");
                scanf("%d",&pos);
                delpos(pos);
                break;
            case 5:
                display();
                break;
            default: 
                printf("Please enter a valid choice \n");
                break;
        }
        printf("Enter your choice of operation : ");
        scanf("%d",&choice);
    }
    return 0;
}
