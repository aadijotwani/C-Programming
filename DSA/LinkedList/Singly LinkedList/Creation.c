#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head = NULL, *newNode, *temp;
    int choice = 1;

    while(choice){
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter the Data: ");
        scanf("%d", &newNode -> data);
        
        newNode-> next = NULL;

        if(head == NULL){
            head = temp = newNode;
        }
        else{
            temp -> next = newNode;
            temp = newNode;
        }

        printf("Add another Node (0/1)\n");
        scanf("%d", &choice);
    }

    //Traversing 
    temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    printf("NULL");
    
    return 0;
}