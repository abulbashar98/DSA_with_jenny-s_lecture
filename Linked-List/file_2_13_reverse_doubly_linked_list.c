#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct returnValues{
    struct node *head;
    struct node *tail;
    int nodeNo;
};


//***** Create a single Doubly linked list node.
struct node *create_single_node_for_doubly_linked_list(){

    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;


    return newnode;

}

//***** Creation of doubly linked list based on users choice
struct returnValues create_doubly_linked_list(struct node *head, struct node *tail, struct node *newnode, int nodeNo){
    
    struct returnValues result;
    int choice = 1;

    while(choice){
        newnode = create_single_node_for_doubly_linked_list();

        if(head == NULL){
            head = tail = newnode;
            nodeNo++;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            nodeNo++;
        }

        printf("\nDo you want to create another node? (Type 1 or 0): ");
        scanf("%d", &choice);

    }

    result.head = head;
    result.tail = tail;
    result.nodeNo = nodeNo;
    
    return result;

}

//***** Display the original list after creation of linked list;
void display_original_linked_list(struct node *head, struct node *tail, int nodeNo){

    tail = head;
    nodeNo = 1;

    while(tail != NULL){
        printf("\nNode no: %d and Node data: %d", nodeNo, tail->data);
        tail = tail->next;
        nodeNo++;
    }

}

//***** Reverse doubly linked list using iteration method;
struct returnValues reverse_doubly_linked_list(struct node *head, struct node *tail){

    struct returnValues result;

    struct node *current_node, *next_node;

    current_node = head;

    while(current_node != NULL){
        next_node = current_node->next;
        current_node->next = current_node->prev;
        current_node->prev = next_node;
        current_node = next_node;
    }

    current_node = head;
    head = tail;
    tail = current_node;

    result.head = head;
    result.tail = tail;

    return result;

}

//***** Display reversed linked list.
void display_reversed_linked_list(struct node *head, struct node *tail, int nodeNo){

    tail = head;
    nodeNo = 1;

    while(tail != NULL){
        printf("\nNode no: %d and Node data: %d", nodeNo, tail->data);
        tail = tail->next;
        nodeNo++;
    }

}

int main(void){

    struct node *head, *tail, *newnode;
    head = tail = NULL;
    int nodeNo = 0;
    struct returnValues returned_list;


    returned_list = create_doubly_linked_list(head,tail,newnode,nodeNo);

    head = returned_list.head;
    tail = returned_list.tail;
    nodeNo = returned_list.nodeNo;

    display_original_linked_list(head, tail, nodeNo);

    returned_list = reverse_doubly_linked_list(head, tail);

    head = returned_list.head;
    tail = returned_list.tail;

    display_reversed_linked_list(head,tail,nodeNo);

    return 0;
}