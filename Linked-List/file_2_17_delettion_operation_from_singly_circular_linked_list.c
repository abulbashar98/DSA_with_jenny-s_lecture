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

//****** Create a single node for singly circular linked list
struct node *create_a_single_node_for_singly_circular_linked_list(struct node *newnode){
    
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    return newnode;

}

//****** Create a singly circular linked-list
struct returnValues create_singly_circular_linked_list(struct node *tail,struct node *newnode,int nodeNo){
    
    struct returnValues result;

    int input_count = 0;
    printf("\nEnter number of nodes you want to create in this singly circular linked list: ");
    scanf("%d" ,&input_count);

    for(int i = 0; i < input_count; i++){
        newnode = create_a_single_node_for_singly_circular_linked_list(newnode);

        if(tail == NULL){
            tail = newnode;
            newnode->next = tail;
            nodeNo++;
        }
        else{
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
            nodeNo++;
        }

    }

    

    result.tail = tail;
    result.nodeNo = nodeNo;

    return result;


}

//****** Display singly_circular_linked-list
void display_singly_circular_linked_list(struct node *tail,int nodeNo){

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

//****** Delete a node from the beginning of singly circular linked list
struct returnValues del_from_beg(struct node *tail,int nodeNo){

    struct node *temp;
    temp = tail->next;
    tail->next = temp->next;
    free(temp);
    nodeNo--;

    struct returnValues result;
    
    result.tail = tail;
    result.nodeNo = nodeNo;
    
    return result;

}

//****** Delete the last node from singly circular linked list
struct returnValues del_from_end(struct node *tail, int nodeNo){

    struct node *second_last_node, *last_node;

    second_last_node = tail->next;
    last_node = second_last_node->next;

    while(last_node->next != tail->next){
        second_last_node = second_last_node->next;
        last_node = last_node->next;
    }

    second_last_node->next = last_node->next;
    free(last_node);
    nodeNo--;
    
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

    returned_list = create_singly_circular_linked_list(tail,newnode,nodeNo);

    tail = returned_list.tail;
    nodeNo = returned_list.nodeNo;

    display_singly_circular_linked_list(tail,nodeNo);
    
    
    int choice_of_deletion = 0;

    printf("\nEnter a number based on the position you want to delete node from, Type 1 to delete from the beginning, Type 2 to delete from the end and Type 3 to delete from a random pos: ");
    
    scanf("%d", &choice_of_deletion);

    if(choice_of_deletion == 1){
        returned_list = del_from_beg(tail, nodeNo);

        tail = returned_list.tail;
        nodeNo = returned_list.nodeNo;
    }
    else if(choice_of_deletion == 2){
        returned_list = del_from_end(tail, nodeNo);

        tail = returned_list.tail;
        nodeNo = returned_list.nodeNo;
    }
    display_singly_circular_linked_list(tail,nodeNo);






    return 0;
}