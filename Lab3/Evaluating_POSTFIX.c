#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int top=-1;
int stk[100];
void push(int val);
int pop();
int eval(char input[],int length);
int main()
{
    char postfix[100];
    int len;
    printf("Enter the postfix expression : ");
    scanf("%s",postfix);
    len=(int)strlen(postfix);
    printf("Result of the expression is %d\n",eval(postfix,len));
    return 0;
}
int eval(char input[],int length){
    int x=0,op1,op2;
    int result=0;
    printf("Traversing the infix expression :");
    for (int i=0;i<length;i++){
        printf("%c\n",input[i]);
    }
    for(x=0;x<length;x++){
        if(isdigit(input[x])){
            push(input[x] - '0');
        }
        else if(input[x]=='^'){
            op1=(int)pop();
            op2=(int)pop();
            result+=pow(op1,op2);
        }
        else if(input[x]=='*' || input[x]=='/'){
            op1=(int)pop();
            op2=(int)pop();
            if(input[x]=='*'){
                result+=(op1*op2);
            }
            else if(input[x]=='/'){
                result+=(op1/op2);
            }
        }
        else if(input[x]=='+' || input[x]=='-'){
            op1=(int)pop();
            op2=(int)pop();
            if(input[x]=='+'){
                result=result+(op1+op2);
            }
            else if(input[x]=='-'){
                result+=(op1-op2);
            }
        }
    }
    return result;
}
void push(int val){
    stk[++top]=val;
}
int pop(){
    return stk[top--];
}
