#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} node;

void display(node *head);
void delBegin(node **head);
void delEnd(node *head);
void delPos(node* head);

int main(){
    node *head = NULL, *newNode, *temp = NULL;
    int choice =1;

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

        printf("add more? (0/1): ");
        scanf("%d", &choice);
    }
    display(head);
    printf("\n");
    delPos(head);
    display(head);
    return 0;
}

void display(node *head){
    node *temp;

    temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp= temp->next;
    }
    printf("NULL\n");
}

void delBegin(node **head){
    if(*head == NULL) return;
    node *temp, *upc = NULL;

    temp = *head;
    if(temp->next != NULL) {
        upc = temp->next;
        upc->prev = NULL;
    }
    *head = upc;

    free(temp);
}

void delEnd(node *head){
    node *temp, *prev = NULL;

    temp = head; 
    while(temp->next != NULL){
        prev = temp;
        temp = temp -> next; 
    }

    prev->next = NULL;

    free(temp);   
}

void delPos(node * head){
    node *temp, *prev, *upc;
    int i = 0, pos;  

    printf("Please enter the pos to delete: ");
    scanf("%d", &pos);
    
    temp = head;
    while(i < pos){
        prev = temp;
        temp = temp->next;
        i++;
    }
    upc = temp->next;

    prev->next = temp->next;
    upc->prev = prev;

    free(temp);
}