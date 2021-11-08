#include <stdio.h>
int fib(int num){
    int res;
    if(num==1)return 0;
    else if(num==2) return 1;
    else  {
     res=fib(num-1)+fib(num-2);
     }
     return res;
}
int main()
{
	int n,x;
    printf("Enter the nth fibonacci number needed : ");
    scanf("%d",&n);
    x=fib(n);
    printf("%d\n",x);
	return 0;
}
