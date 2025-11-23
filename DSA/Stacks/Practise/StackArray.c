#include <stdio.h>

#define n 5

int stack[n];
int top = -1;

void display(){
    if(top == -1){
        printf("Underflow");
    }
    else{
        for(int i=top; i>=0; i--){
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

void push(int x){
    if(top == n-1){
        printf("Overflow\n");
    }
    else{
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top == -1){
        printf("Underflow\n");
    }
    else{
        int item = stack[top];
        top--;
        printf("%d removed from the stack \n", item);
    }
}

void peek(){
    if(top == -1){
        printf("Underflow");
    }
    else{
        printf("%d", stack[top]);
    }
}

void main(){
    push(1);
    display();
    push(2);
    display();
    push(3);
    display();
    pop();
    display();
    peek();
}