#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


void insert_at_the_beginning(struct node *head, struct node *newnode, struct node *temp, int count){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;

    head = newnode;
    count = 1;


    temp = head;

    while(temp != NULL){
        printf("\n node count: %d and data: %d", count, temp->data);
        count++;
        temp = temp->next;

    }

}

struct node *insert_at_the_end(struct node *head, int count){
    
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data you want to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    count++;

    struct node *temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = newnode;

    return head;
}

struct node *insert_at_a_random_given_position(struct node *head, int count, int pos){

    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    struct node *temp = head;
    count = 1;
    while(count != pos){
        temp = temp->next;
        count++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    
    return head;
}


int main(void){

    struct node *head, *newnode, *temp;
    int count = 0;
    int choice = 1;
    head = NULL;
    
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL){
            head = temp = newnode;
            count++;
            printf("\n node count: %d and data: %d",count, head->data);
        }
        else{
            temp->next = newnode;
            count++;
            temp = newnode;
            printf("\n node count: %d and data: %d", count, temp->data);
        }

        printf("\nDo you want to create a new node? Type(1 or 0): ");
        scanf("%d", &choice);

        getchar();
        
    }
    
    
    //***** Insertion of new node at:
    // 1. Insertion at the beginning.
    // 2. Insertion at the end.
    // 3. Insertion in the middle using users given position.

    int choice_of_insertion = 0;

    printf("\nEnter a choice to inset your node. 1 to insert at the beginning. 2 to insert at the end and 3 to insert at some random position:  ");

    scanf("%d", &choice_of_insertion);

    if(choice_of_insertion == 1){
        insert_at_the_beginning(head, newnode, temp, count);
    }
    else if(choice_of_insertion == 2){
        head = insert_at_the_end(head,count);
    }
    else{
        int pos = 0;
        printf("\nEnter a position in node you want to insert new node: ");
        scanf("%d", &pos);
        if(pos > count){
            printf("Invalid Position.");
        }
        else{
           head = insert_at_a_random_given_position(head,count,pos);    
        }
    }

    temp = head;
    count = 1;

    while(temp != NULL){
        printf("\n node count: %d and data: %d", count, temp->data);
        temp = temp->next;
        count++;
    }

    
    return 0;
}