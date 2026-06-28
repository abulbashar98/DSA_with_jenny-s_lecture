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

//****** Create a single doubly linked list node.
struct node *create_a_node_for_doubly(){

    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;


}

//****** Create a doubly linked list based on user's choice.
struct returnValues create_doubly_linked_list(struct node *head, struct node *tail, int nodeNo){
    
    struct node *newnode;
    int choice = 1;
    struct returnValues result;

    
    while(choice){
        newnode = create_a_node_for_doubly();
    
        if(head == NULL){
            head = tail = newnode;
            nodeNo++;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = tail->next;
            nodeNo++;
        }

        printf("Do you want to create another node? (Type 1 or 0): ");
        scanf("%d", &choice);    
    }

    result.head = head;
    result.tail = tail;
    result.nodeNo = nodeNo;


    return result;
}

//***** Display current Doubly linked list based on current head and nodeNo.
void display_current_doubly_linked_list(struct node *head, int nodeNo){

    struct node *temp;
    temp = head;
    nodeNo = 1;

    while(temp != NULL){
            printf("\nNode nodeNo: %d and Node Data: %d ", nodeNo, temp->data);
            temp = temp->next;
            nodeNo++;
    }

}

//***** Delete node from the beginning of doubly linked list.
struct returnValues del_from_beg(struct node *head, int nodeNo){
    
    struct returnValues result;
    struct node *temp;
    temp = head;

    head->next->prev = NULL;
    head = head->next;

    free(temp);
    nodeNo--;

    result.head = head;
    result.nodeNo = nodeNo;

    return result;

}

//***** Delete a node from the end of a doubly linked list;
struct returnValues del_from_end(struct node *head, struct node *tail, int nodeNo){
    
    struct returnValues result;
    struct node *temp;

    temp = tail;

    tail = tail->prev;
    tail->next = NULL;
    free(temp);
    nodeNo--;
   
    result.head = head;
    result.tail = tail;
    result.nodeNo = nodeNo;

    return result;

}

//***** Delete a node from a random position in doubly linked list.
struct returnValues del_from_random_pos(struct node *head, struct node *tail, int nodeNo){

    struct returnValues result;
    
    int pos = 0;
    printf("Enter the specific position you want to delete node from doubly linked list: ");
    scanf("%d", &pos);

    if(pos <= 0 || pos > nodeNo){
        printf("invalid pos");
    }
    else if(pos == 1){
        result = del_from_beg(head,nodeNo);

        head = result.head;
        tail = result.tail;
        nodeNo = result.nodeNo;

        display_current_doubly_linked_list(head,nodeNo);
    }
    else if(pos == nodeNo){
        result = del_from_end(head,tail,nodeNo);

        head = result.head;
        tail = result.tail;
        nodeNo = result.nodeNo;

        display_current_doubly_linked_list(head,nodeNo);
    }
    else{
        
        struct node *temp;
        temp = head;
        int i = 1;

        while(i < pos){
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        nodeNo--;

        result.head = head;
        result.tail = tail;
        result.nodeNo = nodeNo;

        return result;
    
    }

}

int main(void){

    struct node *head, *tail;
    head = NULL;
    tail = NULL;
    int nodeNo = 0;
    struct returnValues returned_list;

    returned_list = create_doubly_linked_list(head,tail,nodeNo);

    head = returned_list.head;
    tail = returned_list.tail;
    nodeNo = returned_list.nodeNo;

    display_current_doubly_linked_list(head, nodeNo);
    

    int choice_of_deletion = 0;

    printf("\nEnter your choice based on the position you want to delete Node from. Type 1 if you want to delete node from beginning of the doubly linked list. Type 2 if you want to delete node from the end of the linked list. Type 3 if you want to delete a node from a random position in doubly linked list: ");
    scanf("%d", &choice_of_deletion);

    if(choice_of_deletion == 1){
        returned_list = del_from_beg(head,nodeNo);

        head = returned_list.head;
        nodeNo = returned_list.nodeNo;

        display_current_doubly_linked_list(head, nodeNo);
    }
    else if(choice_of_deletion == 2){
        returned_list = del_from_end(head,tail,nodeNo);

        tail = returned_list.tail;
        nodeNo = returned_list.nodeNo;

        display_current_doubly_linked_list(head, nodeNo);
    }
    else if(choice_of_deletion == 3){
        returned_list = del_from_random_pos(head,tail,nodeNo);

        head = returned_list.head;
        tail = returned_list.tail;
        nodeNo = returned_list.nodeNo;

        display_current_doubly_linked_list(head,nodeNo);
    }



    return 0;
}