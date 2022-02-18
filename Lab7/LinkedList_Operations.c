#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct node{
    int data;
    struct node *next;
}nod;

void push(int val,nod ** head){
    nod * newnode=(nod *)malloc(sizeof(nod));
    newnode->data=val;
    if(*head==NULL){
        *head=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=*head;
        *head=newnode;
    }
}
void reverse(nod ** head){
    nod *next=NULL,*prev=NULL;
    nod * curr=*head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}

void search(int value,nod *head){
    nod *temp;
    int i=1;
    temp=head;
    while(temp->data!=value && temp->next!=NULL){
        i++;
        temp=temp->next;
    }
    if(temp->next==NULL){
        if(temp->data==value){
            printf("Element is found at position %d\n",i);
        }
        else{
            printf("Element is not in the list \n");
        }
    }
    else{
        printf("Element is found at position %d\n",i);
    }
}

void sort(nod ** head){
    nod *temp,*temphead;
    int tempdata;
    temphead=*head;
    while(temphead!=NULL){
        temp=temphead->next;
        while(temp!=NULL){
            if(temphead->data > temp->data){
                tempdata=temphead->data;
                temphead->data=temp->data;
                temp->data=tempdata;
            }
            temp=temp->next;
        }
        temphead=temphead->next;
    }
}

void concat(nod **head,nod **head2){
    nod *temp=NULL;
    if(head2==NULL){
        printf("The new list is same as the old list\n");
    }
    else{
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=*head2;
    }
}

void display(nod *head){
    nod *temp;
    int i=1;
    temp=head;
    while(temp!=NULL){
        printf("%d element is %d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
}
int main()
{
	int choice,val;
    nod *head=NULL;
    nod *head2=NULL;
    printf("*** MENU ***\n1.Insert \n2.Reverse\n3.Display\n4.Search\n5.Sort\n6.Concatenation\n7.Exit\n");
    printf("Enter the choice of operation : ");
    scanf("%d",&choice);
    while(choice!=7){
        switch(choice){
            case 1:
                printf("Enter the number to be inserted : ");
                scanf("%d",&val);
                push(val,&head);
                break;
            case 2:
                reverse(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Enter the number to be searched : ");
                scanf("%d",&val);
                search(val,head);
                break;
            case 5:
                sort(&head);
                printf("List after sorting\n");
                display(head);
                break;
            case 6:
                printf("Concatenation of two Linked Lists\n");
                printf("******MENU SECOND LIST *******");
                printf("1.Insert Element \n2.Exit\n");
                printf("Enter your choice : ");
                scanf("%d",&choice);
                while(choice!=2){
                    switch(choice){
                        case 1:
                            printf("Enter the element to be inserted : ");
                            scanf("%d",&val);
                            push(val,&head2);
                            break;
                        case 2:
                            exit(0);
                    }
                    printf("Enter your choice : ");
                    scanf("%d",&choice);
                }
                concat(&head,&head2);
                printf("List after concatenation \n");
                display(head);
                break;
        }
        printf("Enter the choice of operation : ");
        scanf("%d",&choice);
    }
	return 0;
}
