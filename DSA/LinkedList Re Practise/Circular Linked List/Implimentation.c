#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void display(node *head);

int main()
{
    node *newNode, *head = NULL, *temp;
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

        printf("Want to add more? (0/1): ");
        scanf("%d", &choice);
    }
    temp->next = head;

    display(head);

    return 0;
}

void display(node *head)
{
    node *temp;

    if (head == NULL)
    {
        printf("List is empty: ");
        return;
    }
    else
    {
        temp = head;
        do  
        {
            printf("%d -> ", temp->data);
            temp = temp->next; 
        }
        while(temp != head);

        printf("%d -> ....", temp->data);
    }
}