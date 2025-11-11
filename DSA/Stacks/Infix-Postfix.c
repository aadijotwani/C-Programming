// Write a program to convert an expression from infix notation to postfix notation.
#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        return -1;
    }

    else
    {
        return stack[top--];
    }
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int isOperand(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9'))
        return 1;
    else
        return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char ch, temp;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0')
    {
        if (isOperand(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while ((temp = pop()) != '(')
                postfix[k++] = temp;
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
