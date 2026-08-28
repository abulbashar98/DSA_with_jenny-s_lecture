#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    struct node *prev;
    int data;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *newnode = NULL;

int que_count = 0;

struct node *create_a_single_doubly_node_for_deque(int x){

    newnode = (struct node *)malloc(sizeof(struct node));
   
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

void enqueue_at_rear(int x){

    newnode = create_a_single_doubly_node_for_deque(x);

    if(front == NULL && rear == NULL){
       
        front = newnode;
        rear = newnode;

        newnode->next = newnode;
        newnode->prev = newnode;
        que_count++;
    }

    else{

        rear->next = newnode;
        newnode->prev = rear;
        rear = newnode;
        newnode->next = front;
        front->prev = newnode;
        que_count++;
    }

}

void dequeue_from_front(){
    if(front == NULL && rear == NULL){
        printf("The queue is empty");
    }
    else if(front == rear){
        struct node *temp;

        temp = front;
        printf("\ndequeued element from front: %d", front->data);

        front = NULL;
        rear = NULL;
        free(temp);
        que_count--;
    }
    else{
        struct node *temp;
        temp = front;
        printf("\ndequeued element from front: %d", front->data);
        front = front->next;
        free(temp);
        que_count--;
    }
}

void enqueue_at_front(int x){

    newnode = create_a_single_doubly_node_for_deque(x);

    if(front == NULL && rear == NULL){
        front = newnode;
        rear = newnode;

        newnode->next = newnode;
        newnode->prev = newnode;
        que_count++;
    }
    else{
        front->prev = newnode;
        newnode->next = front;
        front = newnode;
        newnode->prev = rear;
        rear->next = newnode;
        que_count++;
    }

}

void dequeue_from_rear(){
    if(front == NULL && rear == NULL){
        printf("The queue is empty!");
    }
    else if(front == rear){
        struct node *temp;
        temp = front;
        printf("\ndequeued element from rear: %d", rear->data);
        front = NULL;
        rear = NULL;
        free(temp);
        que_count--;
    }
    else{
        struct node *temp;
        temp = rear;
        rear->prev->next = front;
        printf("\ndequeued element from rear: %d", rear->data);
        rear = rear->prev;
        front->prev = rear;
        free(temp);
        que_count--;
    }


}

void display(){

    if(front == NULL && rear == NULL){
        printf("The que is empty!");
    }
    else{
        struct node *temp;
        temp = front;
        que_count = 1;

        do{
            printf("\nQueue element no: %d and Queue data: %d", que_count, temp->data);
            temp = temp->next;
            que_count++;
        }while(temp->next != front);
    }


}

void get_front(){
    
    if(front == NULL && rear == NULL){
        printf("The queue is empty");
    }
    else{
        printf("\nThe current first element from the front side of this double ended que using FIFO principle is: %d", front->data);
    }

}

void get_rear(){
    
    if(front == NULL && rear == NULL){
        printf("The queue is empty");
    }
    else{
        printf("\nThe current first element from the rear side of this double ended que using FIFO principle is: %d", rear->data);
    }

}


int main(void){


    enqueue_at_front(2);
    enqueue_at_front(4);
    enqueue_at_rear(6);
    enqueue_at_front(8);
    display();
    dequeue_from_front();
    dequeue_from_rear();
    enqueue_at_front(-2);
    enqueue_at_rear(-4);
    display();
    get_front();
    get_rear();
    enqueue_at_rear(-8);
    dequeue_from_front();
    display();



    return 0;
}