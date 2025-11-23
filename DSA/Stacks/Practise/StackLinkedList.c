#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *top = NULL;

void display()
{
    if (top == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        node *temp;
        temp = top;

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void push(int x)
{
    node *newNode;

    newNode = (node *)malloc(sizeof(node));

    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void peek()
{
    if (top == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("the topmost value is %d\n", top->data);
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        node *temp;
        temp = top;

        printf("Popped %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

int main()
{
    push(10);
    display();
    push(20);
    push(30);

    display();

    peek();

    pop(); // should print: Popped 30
    display();

    pop(); // Popped 20
    pop(); // Popped 10

    pop(); // Underflow

    display(); // Underflow

    return 0;
}