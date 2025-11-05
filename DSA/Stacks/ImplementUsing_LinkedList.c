#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x){
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode ->next = top;
    top = newNode;
}

void display(){
    struct node *temp;
    temp = top;
    if(top == NULL){
        printf("Stack is Empty");
    }
    else{
        while(temp != 0){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void peek(){
   
    if(top == NULL){
        printf("Stack is Empty");
    }
    else{
        printf("%d ", top->data);
    }
}

void pop(){
    struct node *temp;

    temp = top;
    if(top == 0){
        printf("UNDERFLOW");
    }
    else{
        top = temp ->next;
        free(temp);
    }
}