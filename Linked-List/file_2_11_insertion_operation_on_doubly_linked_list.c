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
    int count;
};

//***** Create a new doubly linked list NODE
struct node *create_a_new_doubly_linked_list_node(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

//***** Creation of doubly linked list;
struct returnValues create_doubly_linked_list(struct node *head, struct node *tail, int count){

    struct returnValues result;

    head = NULL;
    tail == NULL;
    int choice = 1;
    struct node *newnode;

    while(choice){
        newnode = create_a_new_doubly_linked_list_node();

        if(head == NULL){
            head = tail = newnode;
            count++;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            count++;
        }

        printf("Do you want to create another node? Type(1 or 0): ");
        scanf("%d", &choice);
    }

    result.head = head;
    result.tail = tail;
    result.count = count;

    return result;

}

//***** Display doubly linked list
void display_doubly_linked_list(struct node *head, struct node *tail, int count){

    tail = head;
    count = 1;

    while(tail != NULL){
        printf("\nNode count: %d and Node Data: %d", count, tail->data);
        count++;
        tail = tail->next;
    }

}


//***** Insert a new node at the beginning of doubly linked list
struct returnValues insert_at_beg(struct node *head, struct node *tail, int count){

    struct returnValues returned_list_after_ins_at_beg;

    struct node *newnode;

    newnode = create_a_new_doubly_linked_list_node();

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    count++;

    returned_list_after_ins_at_beg.head = head;
    returned_list_after_ins_at_beg.tail = tail;
    returned_list_after_ins_at_beg.count = count;

    return returned_list_after_ins_at_beg;

}

//***** Insert at the end of doubly linked list.
struct returnValues insert_at_end(struct node *head, struct node *tail, int count){

    struct returnValues returned_list_after_insertion_at_end;

    struct node *newnode;
    newnode = create_a_new_doubly_linked_list_node();

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    count++;

    returned_list_after_insertion_at_end.head = head;
    returned_list_after_insertion_at_end.tail = tail;
    returned_list_after_insertion_at_end.count = count;

    return returned_list_after_insertion_at_end;
}

//***** Insert new node at a random position
struct returnValues insert_at_the_position(struct node *head, struct node *tail, int count){
    
    struct returnValues returned_list;
    int pos = 0;

    printf("Enter the specific position you want to insert the new node: ");
    scanf("%d", &pos);

    if(pos <= 0 || pos > count + 1){
        printf("Invalid position");
    }
    else if(pos == 1){
        returned_list = insert_at_beg(head, tail, count);
        
        head = returned_list.head;
        tail = returned_list.tail;
        count = returned_list.count;

        display_doubly_linked_list(head,tail,count);
    }
    else if(pos == count + 1){
       returned_list = insert_at_end(head,tail,count);
        
        head = returned_list.head;
        tail = returned_list.tail;
        count = returned_list.count;

        display_doubly_linked_list(head, tail, count);
    }
    else{
        struct node *newnode, *temp;
        temp = head;
        newnode = create_a_new_doubly_linked_list_node();

        int i = 1;
        while(i < pos - 1){
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        count++;
         
        struct returnValues result;

        result.head = head;
        result.tail = tail;
        result.count = count;

        return result;
    }

    

}


int main(void){

    struct node *head = NULL;
    struct node *tail = NULL;
    int count = 0;

    struct returnValues returned_list;

    returned_list = create_doubly_linked_list(head,tail,count);
    
    head = returned_list.head;
    tail = returned_list.tail;
    count = returned_list.count;
    
    display_doubly_linked_list(head,tail,count);

    printf("\nEnter a number based on the position you want to insert a new node in doubly linked list. Type 1 to insert at the beginning, type 2 to insert at the end, type 3 to insert at a random position, type 4 to insert after a random position. (1/2/3/4): ");

    int choice_of_insertion = 0;
    scanf("%d", &choice_of_insertion);

    if(choice_of_insertion <= 0 || choice_of_insertion > 4){
        printf("Invalid choice");
    }
    else if(choice_of_insertion == 1){
        returned_list = insert_at_beg(head, tail, count);
        
        head = returned_list.head;
        tail = returned_list.tail;
        count = returned_list.count;

        display_doubly_linked_list(head,tail,count);
    }
    else if(choice_of_insertion == 2){
        returned_list = insert_at_end(head,tail,count);
        
        head = returned_list.head;
        tail = returned_list.tail;
        count = returned_list.count;

        display_doubly_linked_list(head, tail, count);
    }
    else if(choice_of_insertion == 3){
        returned_list = insert_at_the_position(head,tail,count);

        head = returned_list.head;
        tail = returned_list.tail;
        count = returned_list.count;

        display_doubly_linked_list(head,tail,count);

    }




    return  0;
}