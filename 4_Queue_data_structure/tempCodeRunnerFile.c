#include <stdio.h>

#define N 5

int queue[N];

int front = -1;
int rear = -1;


void enqueue(int x){

    if(rear == N -1){
        printf("\nOverflow condition!");
    }
    else if(rear == -1 && front == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }

}

void dequeue(){

    if(front == -1 && rear == -1){
        printf("\nUnderflow condition!");
    }
    else if(front == rear){
        printf("\nDequeued element is: %d", queue[front]);
        front = rear = -1;
    }
    else{
        printf("\nDequeued element is: %d", queue[front]);
        front++;
    }

}

void display(){

    printf("\nCurrent queue: ");
    for(int i = front; i <= rear; i++){
        printf("%d", queue[i]);
    }

    printf("\n");
}


void peek(){

    if(front == -1 && rear == -1){
        printf("queue is empty!");
    }

    else{
        printf("\nCurrent first element in queue(fifo) is: %d", queue[front]);
    }

    

}

int main(void){

    enqueue(4);
    enqueue(12);
    enqueue(15);
    enqueue(17);
    dequeue();
    dequeue();
    peek();
    display();
    dequeue();
    peek();
    display();


    return 0;
}