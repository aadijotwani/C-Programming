#include <stdio.h>
#define n 5

int stack[n];
int top = -1;

void push()
{
    int x;
    printf("Please enter the data: ");
    scanf("%d", &x);

    if (top == n - 1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void peak()
{
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("%d", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

void main()
{
    push();
    display();
}