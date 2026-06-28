#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct returnValues{
    struct node *head;
    int nodeNo;
};

//***** Create a single node of singly linked list type for circular linked list.
struct node *create_a_singly_linked_list_nod_for_circular_linked_list(struct node *newnode){

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    return newnode;

}

//***** Create a singly circular linked list
struct returnValues create_singly_circular_linked_list(struct node *head, struct node *newnode, int nodeNo){

    struct returnValues result;
    
    struct node *temp;
    int count_input = 0;
    
    temp = head;

    printf("Enter the number of nodes you want to create for the singly circular linked list: ");
    scanf("%d", &count_input); 

    for(int i = 0; i < count_input; i++){

        newnode = create_a_singly_linked_list_nod_for_circular_linked_list(newnode);

        if(head == NULL){
            head = temp = newnode;
            newnode->next = head;
            nodeNo++;
        }
        else{
            temp->next = newnode;
            temp = temp->next;
            newnode->next = head;
            nodeNo++;
        }

    }

    result.head = head;
    result.nodeNo = nodeNo;
     
    return result;
    
}

//****** Display singly circular linked list.
void display_singly_circular_linked_list(struct node *head, int nodeNo){

    struct node *temp;
    temp = head;
    nodeNo = 1;

    while(temp->next != head){
        printf("\nNode no: %d and Node data: %d", nodeNo, temp->data);
        temp = temp->next;
        nodeNo++;
    }
    printf("\nNode no: %d and Node data: %d", nodeNo, temp->data);

    if(head == temp->next){
        printf("\nIt is a circular singly linked list");
    }
    else{
        printf("\nIt is not a circular singly linked list");
    }

}

int main(void){

    struct returnValues returned_list;

    struct node *head, *newnode;
    
    head = NULL;
    int nodeNo = 0;

    returned_list = create_singly_circular_linked_list(head,newnode,nodeNo);

    head = returned_list.head;
    nodeNo = returned_list.nodeNo;

    display_singly_circular_linked_list(head, nodeNo);

    return 0;
}