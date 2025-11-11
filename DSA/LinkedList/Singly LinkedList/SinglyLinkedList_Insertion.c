#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void NodeCount(struct node **head);
void Insert_at_Beginning(struct node **head);
void Insert_at_End(struct node **head);
void Insert_at_Position(struct node **head);

int main()
{

    struct node *head = NULL, *newNode, *temp;
    int choice, add = 1, n = 1;

    while (add)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Please enter the Data: ");
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

        printf("do you want to continue? (0/1)");
        scanf("%d", &add);
    }

    while (1)
    {

        printf("Please enter a choice: \n 1.Display the Node: \n 2.Count the Number of Nodes: \n 3.Insert at the Begninning: \n 4.Insert at the End: \n 5.Insert at the Position: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            temp = head;
            while (temp != NULL)
            {
                printf(" %d ->", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
            break;

        case 2:
            NodeCount(&head);
            break;

        case 3:

            Insert_at_Beginning(&head);
            break;

        case 4:
            Insert_at_End(&head);
            break;

        case 5:
            Insert_at_Position(&head);
            break;

        case 6:
            return 0;
        }
    }
}

void NodeCount(struct node **head)
{

    struct node *temp;
    int count = 0;

    temp = *head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Count = %d\n", count);
}

void Insert_at_Beginning(struct node **head)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Please enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = *head;
    *head = newNode;
}

void Insert_at_End(struct node **head)
{
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Please enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Insert_at_Position(struct node **head)
{

    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));

    int pos, i = 2;
    printf("Please enter the position to add the node: ");
    scanf("%d", &pos);

    printf("Enter the Data: ");
    scanf("%d", &newNode->data);

    temp = *head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }

    if (pos == 1)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
