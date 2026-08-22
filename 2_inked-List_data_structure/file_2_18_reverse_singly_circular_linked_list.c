#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct returnValues{
    struct node *tail;
    int nodeNo;
};

//****** Create a single singly circular linked list node
struct node *create_a_single_node(struct node *newnode){

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    return newnode;

}

//****** Create a singly circular linked list
struct returnValues create_a_singly_circular_linked_list(struct node *tail, struct node *newnode, int nodeNo){

    int input_count = 0;
    printf("\nEnter number of nodes you want to create in this singly circular linked list: ");
    scanf("%d", &input_count);

    for(int i = 0; i < input_count; i++){
        newnode = create_a_single_node(newnode);

        if(tail == NULL){
            tail = newnode;
            tail->next = newnode;
        }
        else{
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        nodeNo++;
    }

    struct returnValues result;
    result.tail = tail;
    result.nodeNo = nodeNo;

    return result;

}

//****** Display singly circular linked list
void display_singly_circular_linked_list(struct node *tail, int nodeNo){

    struct node *temp;

    temp = tail->next;
    nodeNo = 1;

    if(tail == NULL){
        printf("List is empty.");
    }
    else{
        do{
            printf("\nNode no: %d and Node data: %d", nodeNo, temp->data);
            temp = temp->next;
            nodeNo++;
        }while(temp != tail->next);
    }

}

//****** reverse singly circular linked list
struct returnValues reverse_singly_circular_linked_list(struct node *tail,int nodeNo){
    

    struct node *head;
    head = tail->next;
    
    struct node *prev, *current, *nextnode;
    prev = tail;
    current = head;
    
    

    do{
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;   
    }while((current != head));

    tail = head;

    struct returnValues result;
    result.tail = tail;
    result.nodeNo = nodeNo;

    return result;
    

}

int main(void){

    struct node *tail, *newnode;
    tail = NULL;
    newnode = NULL;
    int nodeNo = 0;

    struct returnValues returned_list;
    returned_list = create_a_singly_circular_linked_list(tail, newnode, nodeNo);

    tail = returned_list.tail;
    nodeNo = returned_list.nodeNo;

    display_singly_circular_linked_list(tail, nodeNo);

    printf("\n Reversed singly circular linked list: \n");

    returned_list = reverse_singly_circular_linked_list(tail, nodeNo);
    
    tail = returned_list.tail;
    nodeNo = returned_list.nodeNo;


    display_singly_circular_linked_list(tail, nodeNo);


    return 0;
}