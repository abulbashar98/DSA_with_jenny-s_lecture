#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct returnValues{
    struct node *head;
    struct node *tail;
    int nodeNo;
};

//***** Create a single node of singly linked list type for circular linked list.
struct node *create_a_singly_linked_list_node_for_circular_linked_list(struct node *newnode){

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    return newnode;

}

//***** Create a singly circular linked list using head and tail
struct returnValues create_singly_circular_linked_list_with_head_and_tail(struct node *head, struct node *tail, struct node *newnode, int nodeNo){

    struct returnValues result;
    int count_input = 0;
    
    tail = head;

    printf("Enter the number of nodes you want to create for the singly circular linked list: ");
    scanf("%d", &count_input); 

    for(int i = 0; i < count_input; i++){

        newnode = create_a_singly_linked_list_node_for_circular_linked_list(newnode);

        if(head == NULL){
            head = tail = newnode;
            tail->next = head;
            nodeNo++;
        }
        else{
            tail->next = newnode;
            tail = tail->next;
            tail->next = head;
            nodeNo++;
        }

    }

    result.head = head;
    result.tail = tail;
    result.nodeNo = nodeNo;
     
    return result;
    
}

//****** Create a singly circular linked list using only tail
struct returnValues create_singly_circular_linked_list_using_only_tail(struct node *tail, struct node *newnode, int nodeNo){
    
    struct returnValues result;
    
    struct node *temp;
    int count_input = 0;

    temp = tail = NULL;
    nodeNo = 0;

    printf("\nEnter the number of nodes you want to create for the singly circular linked list using only tail: ");
    scanf("%d", &count_input);
    
    for(int i = 0; i < count_input; i++){
        newnode = create_a_singly_linked_list_node_for_circular_linked_list(newnode);

        if(tail == NULL){
            temp = tail = newnode;
            tail->next = tail;
            nodeNo++;
        }
        else{
            tail->next = newnode;
            tail = tail->next;
            nodeNo++;
        }
        tail->next = temp;
    }

    result.tail = tail;
    result.nodeNo = nodeNo;

    return result;

}

//****** Display singly circular linked list.
void display_singly_circular_linked_list(struct node *head, struct node *tail, int nodeNo){

    if(head != NULL){
        tail = head;
        nodeNo = 1;

        while(tail->next != head){
            printf("\nNode no: %d and Node data: %d", nodeNo, tail->data);
            tail = tail->next;
            nodeNo++;
        }
        printf("\nNode no: %d and Node data: %d", nodeNo, tail->data);

        if(head == tail->next){
            printf("\nIt is a circular singly linked list");
        }
        else{
            printf("\nIt is not a circular singly linked list");
        }
    }
    
    
    else{
        
        struct node *temp;
        temp = tail;

        while(tail->next != temp){
            printf("\nNode no: %d and Node data: %d", nodeNo, tail->data);
            tail = tail->next;
            nodeNo++;
        }
        printf("\nNode no: %d and Node data: %d", nodeNo, tail->data);

        if(tail->next == temp){
            printf("\nIt is a circular singly linked list");
        }
        else{
            printf("\nIt is not a circular singly linked list");
        }
    
    }

}

int main(void){

    struct returnValues returned_list;

    struct node *head, *tail, *newnode;
    
    head = NULL;
    tail = NULL;
    int nodeNo = 0;

    returned_list = create_singly_circular_linked_list_with_head_and_tail(head,tail,newnode,nodeNo);

    head = returned_list.head;
    tail = returned_list.tail;
    nodeNo = returned_list.nodeNo;

    display_singly_circular_linked_list(head, tail, nodeNo);

    returned_list = create_singly_circular_linked_list_using_only_tail(tail, newnode, nodeNo);

    tail = returned_list.tail;
    nodeNo = returned_list.nodeNo;
    head = NULL;

    display_singly_circular_linked_list(head, tail, nodeNo);

    return 0;
}