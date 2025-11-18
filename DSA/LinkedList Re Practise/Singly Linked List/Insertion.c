#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head);
void insertBegin(struct node **head);
void insertEnd(struct node *head);
void insertPos(struct node *head);

int main()
{
    struct node *head = NULL, *newNode, *temp;

    int choice = 1;
    while (choice)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Please enter the data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp -> next = newNode;
            temp = newNode; 
        }

        printf("Want to add more Nodes (0/1): ");
        scanf("%d", &choice);
    }

    display(head);
    insertBegin(&head);
    display(head);
    insertEnd(head);
    display(head);
    insertPos(head);
    display(head);
    return 0;
}

void display(struct node *head){
    struct node *temp;

    temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertBegin(struct node **head){
    struct node *newNode;
    
    newNode = (struct node *)malloc(sizeof(struct node));
    
    printf("Please enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct node *head){
    struct node *temp, *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Please enter the data: ");
    scanf("%d", &newNode->data);
    
    newNode->next = NULL;

    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertPos(struct node *head){
    struct node *temp, *newNode;
    int pos,i=0;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Please enter the data: ");
    scanf("%d", &newNode->data);

    printf("Please enter the position: ");
    scanf("%d", &pos);

    temp = head;
    
    while(i<pos-1){
        temp = temp -> next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


