
#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

//**** Create Linked-list with users choice 
struct node *linked_list_creation(struct node *head, struct node *newnode, int count){

    int choice = 1;
    struct node *temp;

    head = NULL;

    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

      

        if(head == NULL){
            head = temp = newnode;
            count++;
            printf("Node Count: %d and Node Data: %d", count, head->data);
        }
        else{
            temp->next = newnode;
            temp = newnode;
            count++;
            printf("Node Count: %d and Node Data: %d", count, temp->data);
        }

        printf("\nDo you want to continue? Type(0 or 1): ");
        scanf("%d", &choice);
    }

    return head;

}


//****** Count length of current Linked-list
void get_length(struct node *head, int count){

    struct node *temp;
    temp = head;
    count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    printf("Node Length is: %d", count);

}

int main(void){

    
    int count = 0; 

    struct node *head, *newnode = NULL;

    head = linked_list_creation(head, newnode, count);
    get_length(head, count);
    
    return 0;
    
}