#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

    if(front == NULL){
        front = newnode;
        rear = newnode;

        rear->next = rear;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }

    getch();

}

void dequeue(){

    if(front == NULL){
        printf("\nQueue is empty!");
    }
    else if(front == rear){

        struct node *temp;
        temp = front;
        printf("\nDequeued element: %d", temp->data);
        
        free(temp);
        front = NULL;
        rear = NULL;
    }
    else{

        struct node *temp;
        temp = front;
        printf("\nDequeued element: %d", temp->data);
        front = front->next;
        free(temp);

    }

}

void display(){

    if(front == NULL){
        printf("\nThe queue is empty!");
    }
    else{
        struct node *temp;

        temp = front;
        int queue_count = 1;

        do{
            printf("\nQueue element no: %d and Queue data: %d", queue_count, temp->data);
            temp = temp->next;
            queue_count++;
        }while(temp != front);

    }

}

void peek(){

    if(front == NULL){
        printf("\nThe queue is empty!");
    }
    else{
        printf("\nCurrent first element in queue following FIFO principle is: %d", front->data);
    }

}




int main(void){

    enqueue(10);
    enqueue(12);
    enqueue(14);
    display();
    dequeue();
    peek();
    display();

  


    return 0;
}