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
    count++;


    temp = head;

    while(temp != 0){
        printf("\n node count: %d and data: %d", count, temp->data);
        temp = temp->next;
        count = count - 1;
    }

}

void insert_at_the_end(){
    
}

void insert_at_a_random_given_position(){
    
}


int main(void){

    struct node *head, *newnode, *temp;
    int count = 0;
    int choice = 1;
    head = 0;
    
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if(head == 0){
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
            insert_at_the_end();
        }
        else{
            insert_at_a_random_given_position();
        }
        
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
        insert_at_the_end();
    }
    else{
        insert_at_a_random_given_position();
    }




    getchar();
    return 0;
}