#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void swap(struct node *head);
void display(struct node *head);

int main()
{
    struct node *head = NULL, *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9, *node10;

    node1 = (struct node *)malloc(sizeof(struct node));
    node2 = (struct node *)malloc(sizeof(struct node));
    node3 = (struct node *)malloc(sizeof(struct node));
    node4 = (struct node *)malloc(sizeof(struct node));
    node5 = (struct node *)malloc(sizeof(struct node));
    node6 = (struct node *)malloc(sizeof(struct node));
    node7 = (struct node *)malloc(sizeof(struct node));
    node8 = (struct node *)malloc(sizeof(struct node));
    node9 = (struct node *)malloc(sizeof(struct node));
    node10 = (struct node *)malloc(sizeof(struct node));

    head = node1;

    node1->data = 17;
    node1->next = node2;

    node2->data = 15;
    node2->next = node3;

    node3->data = 8;
    node3->next = node4;

    node4->data = 12;
    node4->next = node5;

    node5->data = 10;
    node5->next = node6;

    node6->data = 5;
    node6->next = node7;

    node7->data = 4;
    node7->next = node8;

    node8->data = 1;
    node8->next = node9;

    node9->data = 7;
    node9->next = node10;

    node10->data = 6;
    node10->next = NULL;

    display(head);
    swap(head);

    return 0;
}

void swap(struct node *head)
{
    struct node *newNode, *headO = NULL, *headE = NULL, *temp, *t1, *t2;

    temp = head;

    while (temp != NULL)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = temp->data;
        newNode->next = NULL;

        if (temp->data % 2 == 0)
        {
            if (headE == NULL)
            {
                headE = t1 = newNode;
            }
            else
            {
                t1->next = newNode;
                t1 = newNode;
            }
        }

        else
        {
            if (headO == NULL)
            {
                headO = t2 = newNode;
            }
            else
            {
                t2->next = newNode;
                t2 = newNode;
            }
        }
        temp = temp->next;
    }

    if (t1 != NULL)
    {
        t1->next = headO;
    }
    else
    {
        headE = headO;
    }

    printf("\n");
    display(headE);
}

void display(struct node *head)
{
    struct node *temp;

    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}