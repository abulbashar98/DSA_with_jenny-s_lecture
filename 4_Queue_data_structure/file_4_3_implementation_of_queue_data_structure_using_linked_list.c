#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x){

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    
    if(front == NULL && rear == NULL){
        printf("\nQueue is empty!");
    }
    else if(front == rear){

        struct node *temp;
        temp = front;
        printf("\nDequeued element is: %d", front->data);
        free(temp);

        front = NULL;
        rear = NULL;
    }

    else{

        struct node *temp;
        temp = front;

        printf("\nDequeued element: %d", front->data);
        front = front->next;
        free(temp);

    }

}

void display(){

    if(front == NULL && rear == NULL){
        printf("\nQueue is empty!");
    }

    else{
        struct node *temp;
        temp = front;
        int queue_count = 1;

        while(temp != NULL){

            printf("\nQueue No: %d and Queue data: %d", queue_count, temp->data);
            temp = temp->next;
            queue_count++;

    }

}
    

}

void peek(){

    if(front == NULL && rear == NULL){
        printf("\nQueue is empty!");
    }
    else{
        printf("\nFirst queue element(fifo): %d", front->data);
    }

}


int main(void){

    enqueue(10);
    enqueue(15);
    enqueue(20);
    display();
    dequeue();
    peek();
    enqueue(25);
    display();
    dequeue();
    dequeue();
    display();    

    return 0;
}