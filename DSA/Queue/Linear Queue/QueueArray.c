#include <stdio.h>

#define n 5
int queue[n];

int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == n - 1)
    {
        printf("Overflow\n");
    }

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }

    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }

    else if (front == rear)
    {
        printf("dequed %d\n", queue[front]);
        front = rear = -1;
    }

    else
    {
        printf("dequed %d\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow");
    }

    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("the front most element is %d\n", queue[front]);
    }
}

void main(){
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
}