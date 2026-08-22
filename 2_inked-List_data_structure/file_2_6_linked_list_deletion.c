#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


//**** list creation with users choice
struct node *list_creation(int choice, int count, struct node *head, struct node *newnode, struct node *temp){

     while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
    
        if(head == NULL){
            head = temp = newnode;
            count++;
            printf("Node count: %d and Node Data: %d", count, temp->data);
        }
        else{
            temp->next = newnode;
            temp = newnode;
            count++;
            printf("Node count: %d and Node Data: %d", count, temp->data);
        }
        
        printf("\nDo you want to continue? Type(1 or 0): ");
        scanf("%d", &choice);
    }

    return head;

}


//****** Display all the nodes in linked-list with node count and data
void display_list(int count, struct node *head){

    struct node *temp = head;
    count = 1;

    while(temp != NULL){
        printf("\nNode count: %d and Node Data: %d", count, temp->data);
        temp = temp->next;
        count++;
    }

}


//***** Deletion of Node at the BEGINNING of linked list.
struct node *del_at_beg(struct node *head, int count){


    struct node *temp = head;
    head = head->next;
    free(temp);
    count--;

    return head;

}

//***** Deletion of Node at the end of the linked list.
struct node *del_at_end(struct node *head, int count){

    struct node *temp, *prevnode;

    temp = head;

    while(temp->next != NULL){
        prevnode = temp;
        temp = temp->next;
    }

    free(temp);
    prevnode->next = NULL;
    count--;

    return head;

}

//***** Deletion of Node from a random position in linked-list.
struct node *del_at_random_pos(struct node *head, int count){
    
    struct node *temp, *nextnode;
    temp = head;
    int i = 1;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }

    
    
    int pos = 0;
    printf("Enter the pos you want to delete node from: ");
    scanf("%d", &pos);
    
    if(pos > count){
        printf("%d", count);
        printf("Invalid Position");
    }
    else{

        temp = nextnode = head;
        
        while(i < pos){
            temp = nextnode;
            nextnode = temp->next;
            i++;
        }
        temp->next = nextnode->next;
        free(nextnode);
        count--;
    }

    return head;


}


int main(void){

    int choice = 1;
    int count = 0;
    struct node *head, *newnode, *temp;

    head = NULL;

    head = list_creation(choice, count, head, newnode,temp);
    
    display_list(count, head);

    printf("\n");

    printf("Where do you want to delete a node from this linked-list? Type 1 to delete from the beginning, type 2 to delete from the end, Type 3 to delete from a random position: ");

    int choice_of_deletion = 0;
    scanf("%d", &choice_of_deletion);

    if(choice_of_deletion == 1){
        head = del_at_beg(head, count);
        display_list(count, head);
    }

    else if(choice_of_deletion == 2){
       head = del_at_end(head,count);
       display_list(count,head);
    }
    else if(choice_of_deletion == 3){
       head = del_at_random_pos(head,count);
       display_list(count, head);
    }

    return 0;
}