#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void display(node *head);
void del_Start(node **head);
void del_End(node *head);
void del_Pos(node **head);

int main()
{
    node *newNode, *head = NULL, *temp;
    int choice = 1;

    while (choice)
    {
        newNode = (node *)malloc(sizeof(node));

        printf("Data: ");
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

        printf("Add more (0/1): ");
        scanf("%d", &choice);
    }
    display(head);
    // del_Start(&head);
    // display(head);
    // del_End(head);
    // display(head);
    del_Pos(&head);
    display(head);
    return 0;
}

void display(node *head)
{
    node *temp;
    temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void del_Start(node **head)
{
    node *temp;

    temp = *head;
    *head = temp->next;

    free(temp);
}

void del_End(node *head)
{
    node *temp, *prev = NULL;

    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void del_Pos(node **head)
{
    node *temp, *prev = NULL;
    int pos, i = 0;

    printf("Please enter position to delete the data: ");
    scanf("%d", &pos);

    temp = *head;

    if (pos == 0)
    {
        *head = temp->next;
    }

    else
    {
        while (i < pos)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
    }
    free(temp);
}
