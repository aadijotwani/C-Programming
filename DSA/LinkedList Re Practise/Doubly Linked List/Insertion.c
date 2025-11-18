#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

void display(node *head);
void insert_Begin(node **head);
void insert_End(node *head);
void insert_Pos(node **head);

int main()
{
    node *head = NULL, *temp, *newNode;
    int choice = 1;

    while (choice)
    {
        newNode = (node *)malloc(sizeof(node));

        printf("Please enter the data: ");
        scanf("%d", &newNode->data);

        if (head == NULL)
        {
            head = temp = newNode;
        }

        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }

        printf("add more? (0/1): ");
        scanf("%d", &choice);
    }

    display(head);
    return 0;
}

void display(node *head)
{
    node *temp;

    temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert_Begin(node **head)
{

    node *temp, *newNode;

    newNode = (node *)malloc(sizeof(node));

    printf("Please enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void insert_End(node *head)
{
    node *temp, *newNode;

    newNode = (node *)malloc(sizeof(node));

    printf("Please enter the data: ");
    scanf("%d", &newNode->data);

     newNode->next = NULL;
    newNode->prev = NULL;

    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

   newNode -> prev = temp;
   temp->next = newNode;
}

void insert_Pos(node **head)
{
    if(*head == NULL){
        return;
    }

    node *temp, *newNode, *upc;
    int pos, i=0;

    newNode = (node*)malloc(sizeof(node));

    printf("Please enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;
    newNode->prev = NULL;

    printf("Please enter the position: ");
    scanf("%d", &pos);

    temp = *head;
    if(pos == 0){
        newNode->next = *head;
        temp->prev = newNode;
        *head = newNode;
        return;
    }
 
    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    upc = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;
    if(upc!=NULL) upc->prev = newNode;
    temp->next = newNode;
}