#include <stdio.h>
void swap(int *p1,int *p2){
    int t;
    t=*p1;
    *p1=*p2;
    *p2=t;
}

int main()
{
    int a,b;
    printf("Enter two numbers : ");
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    printf("After swapping the value of a is %d and b is %d\n",a,b);
    return 0;
}
