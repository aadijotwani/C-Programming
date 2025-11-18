#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
} node;

void display(node *head);

int main(){
    node *head = NULL, *newNode, *temp;
    int choice = 1;

    while(choice){
        newNode = (node*)malloc(sizeof(node));

        printf("Please enter the data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL){
            head = temp = newNode;
        }
        
        else{
            temp->next = newNode;
            newNode->prev = temp; 
            temp = newNode;
        }

        printf("Enter more data? (0/1): ");
        scanf("%d", &choice);
    }

    display(head);
    return 0;
}


void display(node *head){
    node *temp; 
    
    temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}



