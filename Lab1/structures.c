#include <stdio.h>
//Declaration of stucture
struct student{
    int id;
    int age;
    int marks;
};
void accept_input(struct student* s1){
    printf("Enter the id : ");
    scanf("%d",&s1->id);
    printf("Enter the age : ");
    scanf("%d",&s1->age);
    printf("Enter the marks : ");
    scanf("%d",&s1->marks);
}
void display_output(struct student s1){
    printf("Student details are : \n");
    printf("Id - %d\t",s1.id);
    printf("Age - %d\t",s1.age);
    printf("Marks - %d\n",s1.marks);
}
int main(){
    int n,i;//n denotes the number of students
    printf("Enter the number of students : ");
    scanf("%d",&n);
    struct student s[n];
    for(i=0;i<n;i++){
        accept_input(&s[i]);//passing the memory address of the structure element
    }
    for(i=0;i<n;i++){
        display_output(s[i]);
    }
    return 0;
}
