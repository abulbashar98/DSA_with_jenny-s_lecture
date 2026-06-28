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

//***** Create a single node of singly linked list type for circular linked list.
struct node *create_a_singly_linked_list_node_for_circular_linked_list(struct node *newnode){

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    return newnode;

}

//****** Create a singly-circular linked list using tail pointer only.
struct returnValues create_singly_circular_linked_list_using_only_tail(struct node *tail, struct node *newnode, int nodeNo){
    
    struct returnValues result;
    

    int input_count = 0;

    printf("\nEnter the number of nodes you want to create in singly-circular linked list: ");
    scanf("%d", &input_count);

    if(input_count <= 0){
        printf("Invalid input");
    }
    else{
        for(int i = 0; i < input_count; i++){
            newnode = create_a_singly_linked_list_node_for_circular_linked_list(newnode);

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
    }
    
    result.tail = tail;
    result.nodeNo = nodeNo;
    
    return result;

}

//****** Display singly circular linked list using tail only.
void display_singly_circular_linked_list_using_only_tail(struct node *tail, int nodeNo){

    struct node *temp;

    if(tail == NULL){
        printf("List is Empty.");
    }

    else{
        temp = tail->next;

        nodeNo = 1;

        do{
            printf("\nNode no: %d and Node data: %d", nodeNo, temp->data);
            temp = temp->next;
            nodeNo++;
        }while((temp != tail->next));
    }
}

//****** Insert a node at the beg of the singly-circular linked list;
struct returnValues insert_at_beg(struct node *tail, int nodeNo){

    struct node *newnode;
    newnode = create_a_singly_linked_list_node_for_circular_linked_list(newnode);

    struct returnValues result;
    

    if(tail == NULL){
        tail = newnode;
        newnode->next = tail;
        nodeNo++;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
        nodeNo++;
    }

    result.tail = tail;
    result.nodeNo = nodeNo;

    return result;

}

//****** Insert a node at the end of the singly circular linked-list
struct returnValues insert_at_the_end(struct node *tail, int nodeNo){
    
    struct returnValues result;

    struct node *newnode;
    newnode = create_a_singly_linked_list_node_for_circular_linked_list(newnode);

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
    
    result.tail = tail;
    result.nodeNo = nodeNo;

    return result;

}

//***** Insert a node at a random position of singly circular linked list
struct returnValues insert_at_a_random_position(struct node *tail, int nodeNo){
    
    
    struct returnValues result;

    int pos = 0;
    printf("\nEnter a position you want to insert the newnode: ");
    scanf("%d", &pos);
     
    if(pos <= 0 || pos > nodeNo + 1){
        printf("Invalid Position");
    }
    else if(pos == 1){
        return insert_at_beg(tail, nodeNo);

    }
    else if(pos == nodeNo + 1){
        return insert_at_the_end(tail, nodeNo);
    }

    else{

        struct node *newnode;
        newnode = create_a_singly_linked_list_node_for_circular_linked_list     (newnode);
        
        struct node *temp;
        temp = tail->next;
        int i = 1;

        while(i < pos - 1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        nodeNo++;

        result.tail = tail;
        result.nodeNo = nodeNo;
    
        return result;

    }

    


}

int main(void){

    struct returnValues returned_list;

    struct node *tail, *newnode;
    tail = NULL;
    newnode = NULL;
    int nodeNo = 0;

    returned_list = create_singly_circular_linked_list_using_only_tail(tail, newnode, nodeNo);

    tail = returned_list.tail;
    nodeNo = returned_list.nodeNo;

    display_singly_circular_linked_list_using_only_tail(tail, nodeNo);


    int choice_of_insertion = 0;

    printf("\nEnter a number based on the position you want to insert a new node in singly circular linked list. Type 1 to insert at the beginning. Type 2 to insert at the end. Type 3 to insert at a random position: ");

    scanf("%d", &choice_of_insertion);

    if(choice_of_insertion == 1){
        returned_list = insert_at_beg(tail, nodeNo);

        tail = returned_list.tail;
        nodeNo = returned_list.nodeNo;

        display_singly_circular_linked_list_using_only_tail(tail, nodeNo);

    }
    else if(choice_of_insertion == 2){
        returned_list = insert_at_the_end(tail, nodeNo);

        tail = returned_list.tail;
        nodeNo = returned_list.nodeNo;

        display_singly_circular_linked_list_using_only_tail(tail, nodeNo);

    }
    else if(choice_of_insertion == 3){
        returned_list = insert_at_a_random_position(tail, nodeNo);

        tail = returned_list.tail;
        nodeNo = returned_list.nodeNo;

        display_singly_circular_linked_list_using_only_tail(tail, nodeNo);
    }

    return 0;
}