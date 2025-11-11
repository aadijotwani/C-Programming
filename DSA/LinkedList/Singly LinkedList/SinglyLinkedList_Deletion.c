#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void del_begin(struct node *head);
void del_end(struct node *head);
void del_pos(struct node *head);
void display(struct node *head);

int main(){

    struct node *head=NULL, *newNode, *temp;
    int choice=1;

    while(choice){
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter Data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL){
            head = temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }

        printf("Want to add more? (0/1): ");
        scanf("%d", &choice);
    }

    del_begin(head);
    del_end(head);
    del_pos(head);
    display(head);

    return 0;
}

void del_begin(struct node *head){
    struct node *temp;

    temp = head;
    head = temp->next;

    free(temp);
}

void del_end(struct node *head){
    struct node *temp, *prev;

    temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    if(temp == head){
        head = NULL;
    }
    else{
        prev->next = NULL;
    }
    free(temp);

}

void del_pos(struct node *head){
    struct node *temp, *prev;
    int pos, i=1;

    printf("Please enter the position: ");
    scanf("%d", &pos);

    temp = head;
    while(i<pos){
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
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