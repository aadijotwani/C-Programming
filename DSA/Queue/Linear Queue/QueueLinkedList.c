#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue(int x)
{
    node *newNode;

    newNode = (node *)malloc(sizeof(node));

    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void display()
{
    node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dequeue()
{
    node *temp;

    if (front == NULL && rear == NULL)
    {
        printf("Underflow\n");
    }
    else if (front == rear)
    {
        printf("Removed %d\n", front->data);
        temp = front;
        front = rear = NULL;
        free(temp);
    }

    else
    {
        printf("Removed %d\n", front->data);
        temp = front;
        front = temp->next;
        free(temp);
    }
}

void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("the value at the starting is %d\n", front->data);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    peek();
    display();
    dequeue();
    peek();
    display();
}