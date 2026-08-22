#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    struct node *prev;
    int data;
};

struct returned_list{
    struct node *head;
    struct node *tail;
    int nodeNo;
};

//********* create a single node for doubly circular linked list
struct node *create_a_single_node_for_doubly_circular_linked_list(struct node *newnode){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);

    return newnode;
}

//******** Create a doubly circular linked list
struct returned_list create_a_doubly_circular_linked_list(struct node *head, struct node *tail, struct node *newnode, int nodeNo){

    int input_no_of_nodes = 0;
    printf("Enter the number of nodes you want to create in this linked_list: ");
    scanf("%d", &input_no_of_nodes);

    if(input_no_of_nodes <= 0){
        printf("Invalid input!");
    }
    else{
        for(int i = 0; i < input_no_of_nodes; i++){
            newnode = create_a_single_node_for_doubly_circular_linked_list(newnode);

            if(head == NULL){
                head = newnode;
                tail = newnode;

                newnode->prev = newnode;
                newnode->next = newnode;
                nodeNo++;
            }

            else{
                newnode->prev = tail;
                newnode->next = head;
                tail->next = newnode;
                head->prev = newnode;
                tail = newnode;
                nodeNo++;
            }
        }
    }

    
    struct returned_list return_list;

    return_list.head = head;
    return_list.tail = tail;
    return_list.nodeNo = nodeNo;

    return return_list;

}

//******** Insert node at the begining
struct returned_list insert_node_at_the_beg(struct node *head, struct node *tail, int nodeNo){
    struct node *newnode;
    newnode = create_a_single_node_for_doubly_circular_linked_list(newnode);

    if(head == NULL){
        head = newnode;
        tail = newnode;
        newnode->prev = newnode;
        newnode->next = newnode;
        nodeNo++;
    }

    else{
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        head = newnode;
        nodeNo++;
    }

    struct returned_list return_list;

    return_list.head = head;
    return_list.tail = tail;
    return_list.nodeNo = nodeNo;

    return return_list;

}

//******** Insert node at the end
struct returned_list insert_at_the_end(struct node *head, struct node *tail, int nodeNo){
    struct node *newnode;
    newnode = create_a_single_node_for_doubly_circular_linked_list(newnode);

    if(head == NULL){
        head = newnode;
        tail = newnode;
        newnode->prev = newnode;
        newnode->next = newnode;
        nodeNo++;
    }
    else{
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        tail->next = newnode;
        tail = newnode;
        nodeNo++;        
    }

    struct returned_list return_list;

    return_list.head = head;
    return_list.tail = tail;
    return_list.nodeNo = nodeNo;

    return return_list;

}

//******** Insert node at a random postion
struct returned_list insert_node_at_a_random_pos(struct node *head, struct node *tail,int input_position, int nodeNo){
    struct node *newnode;
    newnode = create_a_single_node_for_doubly_circular_linked_list(newnode);

    if(head == NULL){
        head = newnode;
        tail = newnode;
        newnode->prev = newnode;
        newnode->next = newnode;
        nodeNo++;
    }
    else{
        struct node *temp;
        temp = head;

        int i = 1;
        while(i < input_position - 1){
            temp = temp->next;
            i++;
        }

        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        nodeNo++;
    }

    struct returned_list return_list;

    return_list.head = head;
    return_list.tail = tail;
    return_list.nodeNo = nodeNo;

    return return_list;

}

//******** Display doubly circular linked list
void display_doubly_circular_linked_list(struct node *head, struct node *tail, int nodeNo){

    struct node *temp;

    temp = head;
    nodeNo = 1;

    if(head == NULL){
        printf("Empty linked list");
    }
    else{
        do{
            printf("\nNode No: %d and Node Data: %d", nodeNo, temp->data);
            temp = temp->next;
            nodeNo++;
        }while(temp != head);
    }
}



int main(void){
    
    struct node *head,*tail,*newnode;
    head = NULL;
    tail = NULL;
    newnode = NULL;
    int nodeNo = 0;


    struct returned_list result;

    result = create_a_doubly_circular_linked_list(head,tail,newnode,nodeNo);
    
    head = result.head;
    tail = result.tail;
    nodeNo = result.nodeNo;


    display_doubly_circular_linked_list(head,tail,nodeNo);

    int input_position = 0;
    printf("\nEnter the position you want to insert the new node: ");
    scanf("%d", &input_position);

    if(input_position < 0 || input_position > nodeNo + 1){
        printf("Invalid input position");
    }
    else{
        if(input_position == 1){
            result = insert_node_at_the_beg(head,tail,nodeNo);

            head = result.head;
            tail = result.tail;
            nodeNo = result.nodeNo;
        }
        else if(input_position == nodeNo + 1){
            result = insert_at_the_end(head,tail,nodeNo);
            
            head = result.head;
            tail = result.tail;
            nodeNo = result.nodeNo;
        }
        else{
            result = insert_node_at_a_random_pos(head,tail,input_position,nodeNo);

            head = result.head;
            tail = result.tail;
            nodeNo = result.nodeNo;
        }

        display_doubly_circular_linked_list(head,tail,nodeNo);
    }
    
    return 0;
}