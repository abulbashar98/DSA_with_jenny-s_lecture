#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


//***** create linked-list 
struct node *creation_of_linked_list(struct node *head, struct node *newnode, int count){
    
    struct node *temp;
    int choice = 1;


    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
    
        if(head == NULL){
            head = temp = newnode;
            count++;
        }
        else{
            temp->next = newnode;
            temp = newnode;
            count++;
        }

        printf("\nDo you want to create a new node? Type(1 or 0:)");
        scanf("%d", &choice);    
    }
    
    return head;

}

//***** Display Original List
void display_original_list(struct node *head, int count){

    struct node *temp = head;
    count = 0;

    while(temp != NULL){
        count++;
        printf("\nNode Count: %d and Node Data: %d ", count, temp->data);
        temp = temp->next;
    }

}

//***** Reverse linked-list using iterative method
struct node *reverse_linked_list(struct node *head){

    struct node *prevnode, *currentnode, *nextnode;
    prevnode = NULL;
    currentnode = nextnode = head;

    while(nextnode != NULL){
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }

    head = prevnode;
    

    return head;

}

//**** Display reversed list
void display_reversed_list(struct node *head){

    struct node *temp = head;

    int count = 0;

    while(temp != NULL){
        count++;
        printf("\nNode count: %d and Node data: %d", count, temp->data);
        temp = temp->next;
    }



}

int main(void){

    struct node *head, *newnode;
    head = NULL;
    int count = 0;
    int choice = 1;
    
    head = creation_of_linked_list(head, newnode, count);
    display_original_list(head, count);
    head = reverse_linked_list(head);
    display_reversed_list(head);


        


    return 0;
}