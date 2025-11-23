#include <stdio.h>

#define n 5
int queue[n];

int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % n == front)
    {
        printf("Overflow\n");
    }
    else
    {
        rear = (rear + 1) % n;
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
        printf("Dequeued %d\n", queue[front]);
        front = rear = -1;
    }

    else{
        printf("Dequeued %d\n", queue[front]);
        front = (front+1)%n;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Underflow\n");
    }
    else{
        for(int i=front; i!=rear; i=(i+1)%n){
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[rear]);
    }
}


int main()
{
    // Initial state
    display(); // Underflow

    // Enqueue test
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display(); // Expected: 10 20 30 40

    // Circular wrap test
    dequeue(); // removes 10
    dequeue(); // removes 20
    display(); // Expected: 30 40

    enqueue(50);
    enqueue(60);
    display(); // Expected circular: 30 40 50 60

    // Overflow test
    enqueue(70); // Should say Overflow

    // More dequeue tests
    dequeue(); // removes 30
    dequeue(); // removes 40
    display(); // Expected: 50 60

    dequeue(); // removes 50
    dequeue(); // removes 60 → queue becomes empty
    display(); // Underflow

    // Underflow test // Underflow
     enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    return 0;
}
