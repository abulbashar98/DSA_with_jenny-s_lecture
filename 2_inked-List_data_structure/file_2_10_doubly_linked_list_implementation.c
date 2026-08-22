
#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
    struct node *prev;
};

//****** Create doubly linked list
struct node *doubly_linked_list_creation(struct node *head){
   
    head = NULL;
    struct node *newnode; 
    int choice = 1;
    
    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        // For the creation of First Node
        // head = newnode;
    
     

        // For the creation of SECOND node
        /*
        if(head == NULL){
            head = newnode;
         }
        else{
            head->next = newnode;
            newnode->prev = head;
        }
        */

    
        // For the creation of MULTIPLE nodes beyond two
    
        struct node *temp;

        if(head == NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode; 
        }
    
        printf("Do you want to create another node? Type(1 or 0): ");
        scanf("%d", &choice);
    }
    
    return head;
}


//****** Display doubly linked list
void display_doubly_linked_list(struct node *head){

    struct node *temp = head;
    int count = 1;

    while(temp != NULL){
        printf("\nNode count: %d and Node Data: %d", count, temp->data);
        temp = temp->next;
        count++;
    }
}

int main(void){

    struct node *head;
    head = doubly_linked_list_creation(head);
    display_doubly_linked_list(head);



    return 0;
}