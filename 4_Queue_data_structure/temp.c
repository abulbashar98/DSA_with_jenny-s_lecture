#include <stdio.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *front = NULL;
struct node *rear = NULL;

int que_count = 0;


struct node *create_a_single_doubly_node_for_deque(int x){
    
    struct node *newnode;
    
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;

}

void enqueue_at_front(int x){

    struct node *newnode;

    newnode = create_a_single_doubly_node_for_deque(x);

    if(front == NULL && rear == NULL){
        front = newnode;
        rear = newnode;

        newnode->next = newnode;
        newnode->prev = newnode;

        que_count++;

    }

}






int main(void){


    return 0;
}