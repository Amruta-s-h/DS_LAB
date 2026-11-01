#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int isValid(char str[]) {
    int i;
    char ch;

    for (i = 0; str[i] != '\0'; i++) {

        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        }

        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {

            if (top == -1)
                return 0;

            ch = pop();

            if ((str[i] == ')' && ch != '(') ||
                (str[i] == '}' && ch != '{') ||
                (str[i] == ']' && ch != '[')) {
                return 0;
            }
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char str[MAX];

    printf("Enter parentheses: ");
    scanf("%s", str);

    top = -1;

    if (isValid(str))
        printf("Valid Parentheses\n");
    else
        printf("Invalid Parentheses\n");

    return 0;
}
