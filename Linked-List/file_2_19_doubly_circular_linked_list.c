#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    struct node *prev;
    int data;
};

struct return_values{
    struct node *head;
    struct node *tail;
    int nodeNo;
};

//****** Create a single node for doubly circular linked list
struct node *create_a_single_node_for_doubly_circular_linked_list(void){
    struct node *newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("Enter Data: ");
    scanf("%d", &newnode->data);

    return newnode;

}

//****** Create a doubly circular linked list.
struct return_values create_doubly_circular_linked_list(struct node *head, struct node *tail, int nodeNo, struct node *newnode){

    int input_no = 0;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &input_no);

    if(input_no > 0){

        for(int i = 0; i < input_no; i++){
            newnode = create_a_single_node_for_doubly_circular_linked_list();

            if(head == NULL){
                head = tail = newnode;
                tail->next = tail;
                head->prev = head;
                nodeNo++;
            }
            else{
                newnode->prev = tail;
                newnode->next = head;
                tail->next = newnode;
                head->prev = newnode;
                tail = tail->next;
            }
        }

        
        struct return_values return_list;

        return_list.head = head;
        return_list.tail = tail;
        return_list.nodeNo = nodeNo;

        return return_list;

    }
    else{
        printf("Invalid number!");
    }

}

//****** Display doubly circular linked list
void display_doubly_circular_linked_list(struct node *head, int nodeNo){

    struct node *temp;
    temp = head;
    nodeNo = 1;

    do{
        printf("\nNode no: %d and Node data: %d", nodeNo, temp->data);
        temp = temp->next;
        nodeNo++;    
    }while(temp != head);

}

int main(void){

    struct node *head, *tail, *newnode;
    head = NULL;
    tail = NULL;
    int nodeNo = 0;


    struct return_values result;

    result = create_doubly_circular_linked_list(head,tail,nodeNo,newnode);

    head = result.head;
    tail = result.tail;
    nodeNo = result.nodeNo;

    display_doubly_circular_linked_list(head, nodeNo);



    return 0;
}