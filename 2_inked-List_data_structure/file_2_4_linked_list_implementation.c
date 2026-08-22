#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};


int main(void){
    
    //***** creation of HEAD or START pointer and FIRST node
    /*
    struct node *head, *newnode;
    head = 0;

    newnode = (struct node*)malloc(sizeof(struct nodes*));
    
    printf("Enter Data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    head = newnode;

    printf("\n%d", head->data);

    */

    //***** creation of SECOND node, and making first Head node point to SECOND node
    
    /*
    struct node *head, *newnode;
    head = 0;

    newnode = (struct node*)malloc(sizeof(struct nodes*));
    
    printf("Enter Data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    
    if(head == 0){
        head = newnode;
        printf("\n%d", head->data);
    }

    newnode = (struct node*)malloc(sizeof(struct nodes*));
    
    printf("\nEnter Data:");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    head->next = newnode;

    printf("\n%d", newnode->data);

    */

    //***** creation of Third node using a *temp, and making *temp point to each newnode created to make the linked list.

    struct node *head, *newnode, *temp;
    head = 0;
    int choice = 1;


    while(choice){
        newnode = (struct node*)malloc(sizeof(struct nodes*));
    
        printf("Enter Data:");
        scanf("%d", &newnode->data);
        newnode->next = 0;
    
        if(head == 0){
            head = temp = newnode;
            printf("\n%d", head->data);
        }
        else{
            temp->next = newnode;
            temp = newnode;
            printf("\n%d", newnode->data);
        }

        printf("\nDO you want to continue?(Type: (1,0)): ");
        scanf("%d", &choice);
    }
    


    //****** Traverse linked list node using *temp.
    temp = head;
    while(temp != 0){
        printf("%d", temp->data);
        temp = temp->next;
    }
    
    
    return 0;
}