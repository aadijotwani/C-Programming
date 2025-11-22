#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void display(node *head);
void insertBeg(node **head);
void insertEnd(node **head);
void insertPos(node **head);

int main()
{
    node *newNode, *temp, *head = NULL;
    int choice = 1;

    while (choice)
    {
        newNode = (node *)malloc(sizeof(node));

        printf("Please enter the data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
        }

        else
        {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Want to add more? (0/1)? ");
        scanf("%d", &choice);
    }
    temp->next = head;

    display(head);
    insertPos(&head);
    display(head);

    return 0;
}

void display(node *head)
{
    node *temp;

    if (head == NULL)
    {
        printf("List is empty ");
        return;
    }

    else
    {
        temp = head;
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);

        printf("%d -> .....\n", temp->data);
    }
}

void insertBeg(node **head)
{
    node *temp, *newNode;

    newNode = (node *)malloc(sizeof(node));
    printf("Please enter the data: ");
    scanf("%d", &newNode->data);

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }

    temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = *head;
}

void insertEnd(node **head)
{
    node *newNode, *temp;

    temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }

    newNode = (node *)malloc(sizeof(node));

    printf("Please enter the data: ");
    scanf("%d", &newNode->data);

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertPos(node **head)
{
    node *newNode, *temp, *prev;
    int i = 1, pos;

    newNode = (node *)malloc(sizeof(node));

    printf("Please enter the data: ");
    scanf("%d", &newNode->data);

    printf("Please enter the position to insert: ");
    scanf("%d", &pos);

    temp = *head;
    if (*head == NULL)
    {
        if (pos == 0)
        {
            *head = newNode;
            newNode->next = *head;
        }
        else
        {
            printf("List is empty");
            return;
        }
    }
    else
    {
        if (pos == 0)
        {
            newNode->next = *head;
            

            while(temp->next != *head){
                temp = temp->next;
            }
            temp->next = newNode; 
            
            *head = newNode;
        }
        else
        {
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}