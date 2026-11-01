#include<stdio.h>
#include<ctype.h>
int top=-1;
char stack[100];
void push(char ch)
{
    stack[++top]=ch;
}
int pop()
{
    return stack[top--];
}
int precedence(char ch)
{
    if(ch=='+'||ch=='-'){
        return 1;
    }
    if(ch=='*'||ch=='/'){
        return 2;
    }
    return 0;
}
int main()
{
    char postfix[100],infix[100];
    int i,j=0;
    printf("enter infix string:");
    scanf("%s",infix);
    for(int i=0;infix[i]!='\0';i++){
        char ch=infix[i];
        if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(top!=-1&&stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(ch)&&stack[top]!='(')
            {
                postfix[j++]=pop();
            }
            push(ch);

        }


    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("postfix expression:%s",postfix);

}
