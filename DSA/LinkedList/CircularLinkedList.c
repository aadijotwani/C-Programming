#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head);
void Insert_at_Beginning(struct node **head);
void Insert_at_End(struct node **head);
void Insert_at_Position(struct node **head);

int main()
{
    struct node *head = NULL, *newNode, *temp;
    int choice = 1;

    while (choice)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("Enter Data: ");
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

    if (temp != NULL)
        temp->next = head;

    display(head);

    while (1)
    {
        printf("Please enter a choice: \n1.Display the Node: \n2.Insert at the Begninning: \n3.Insert at the End: \n4.Insert at the Position: \n5.Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(head);
            break;

        case 2:
            Insert_at_Beginning(&head);
            break;

        case 3:
            Insert_at_End(&head);
            break;

        case 4:
            Insert_at_Position(&head);
            break;

        case 5:
            return 0;
        }
    }
}

void display(struct node *head)
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("%d -> ", temp->data);

    printf("%d -> (back to start)\n", head->data);
}

void Insert_at_Beginning(struct node **head)
{

    struct node *newNode, *temp = *head;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Please enter the data: ");
    scanf("%d", &newNode->data);


    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }

    else
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }

        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void Insert_at_End(struct node **head)
{
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Please enter the data: ");
    scanf("%d", &newNode->data);

    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }

    else
    {
        temp = *head;

        while (temp->next != *head)
        {
            temp = temp->next;
        }

        newNode->next = *head;
        temp->next = newNode;
    }
}

void Insert_at_Position(struct node **head)
{
    struct node *newNode, *temp;
    int pos, i = 1;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    // If list is empty and position is 1
    if (*head == NULL && pos == 1)
    {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    // If inserting at beginning (pos == 1)
    if (pos == 1)
    {
        temp = *head;
        // traverse till last node
        while (temp->next != *head)
        {
            temp = temp->next;
        }

        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
        return;
    }

    // Insert at any other position
    temp = *head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
