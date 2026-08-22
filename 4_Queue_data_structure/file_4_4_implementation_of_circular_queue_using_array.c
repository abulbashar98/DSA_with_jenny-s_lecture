
#include <stdio.h>

#define N 5
int queue[N];

int front = -1;
int rear = -1;

void enqueue(int x){

    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
        printf("\n%d", queue[rear]);
    }
    else if((rear + 1) % N == front){
        printf("\nQueue is full. Overflow condition.");
    }
    else{
        rear = (rear + 1) % N;
        queue[rear] = x;
        printf("\n%d", queue[rear]);
    }

}

void dequeue(){

    if(front == -1 && rear == -1){
        printf("\nThe queue is empty!");
    }
    else if(front == rear){
        printf("\nDequeued element is: %d", queue[front]);
        front = rear = -1;
    }
    else{
        printf("\nDequeued element is: %d", queue[front]);    
        front = (front + 1) % N;
    }
}

void display(){

    if(front == -1 && rear == -1){
        printf("The queue is empty!");
    }
    else{
        int i = front;
        int queue_count = 1;
        do{
            printf("\nQueue element No: %d and Queue Data: %d", queue_count, queue[i]);
            i = (i+1) % N;
            queue_count++;
        }while((i % N) != (rear + 1));
    }

}

void peek(){

    if(front == -1 && rear == -1){
        printf("The queue is empty!");
    }
    else{
        printf("\nThe current first element of the queue following FIFO principle is: %d", queue[front]);
    }

}





int main(void){

    enqueue(8);
    enqueue(16);
    enqueue(24);
    enqueue(32);
    display();
    dequeue();
    enqueue(40);
    enqueue(48);
    peek();
    dequeue();
    peek();
    display();
    



    return 0;
}