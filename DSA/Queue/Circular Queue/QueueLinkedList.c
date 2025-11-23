#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *front = 0;
node *rear = 0;

void enqueue(int x)
{
    node *newNode;

    newNode = (node *)malloc(sizeof(node));

    newNode->data = x;
    newNode->next = 0;

    if (front == 0 && rear == 0)
    {
        front = rear = newNode;
        newNode->next = front;
    }
    else
    {
        rear->next = newNode;
        newNode->next = front;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == 0 && rear == 0)
    {
        printf("Underflow");
        return;
    }

    node *temp;
    temp = front;

    if (front == rear)
    {
        printf("Dequeued %d\n", front->data);
        front = rear = NULL;
        free(temp);
    }
    else
    {
        printf("Dequeued %d\n", front->data);
        front = temp->next;
        free(temp);

        rear->next = front;
    }
}

void display()
{
    if (front == 0 && rear == 0)
    {
        printf("Underflow\n");
        return;
    }

    node *temp;

    temp = front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;

    } while (temp != front);
}