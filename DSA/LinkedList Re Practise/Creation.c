#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void display(struct node *head);

int main(){
    struct node *head = NULL, *newNode, *temp;
    int choice = 1;

    while(choice){
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Please enter the data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL){
            head = temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }

        printf("Add another node? ");
        scanf("%d", &choice);
    }
    
    display(head);

    return 0;
}


void display(struct node *head){
    struct node *temp;

    temp = head;
    while(temp != NULL){
        printf("data -> %d  ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

