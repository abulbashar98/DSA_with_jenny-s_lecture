#include <stdio.h>

#define N 5

int deque[N];

int front = -1;
int rear = -1;

void dequeue_from_front(){

    if(front == -1 && rear == -1){
        printf("\nThe queue is empty!");
    }
    else if(front == rear ){
        printf("\ndequeued element from front: %d", deque[front]);
        front = rear = -1;
    }
    else if(front == N - 1 && rear >= 0){
        printf("\ndequeued element from front: %d", deque[front]);
        front = 0;
    }
    else{
        printf("\ndequeued element from front: %d", deque[front]);
        front++;
    }

}

void enqueue_at_rear(int x){

    if(front == -1 && rear == -1){
        front = rear = 0;
        deque[rear] = x;
    }
    else if((rear == N - 1) && (front == 0)){
        printf("The Queue is full.");
    }
    else if((rear == N -1) && (front != 0)){
        rear = 0;
        deque[rear] = x;
    }
    else if(rear + 1 == front){
        printf("The queue is full!");
    }
    else{
        rear++;
        deque[rear] = x;
    }

}

void enqueue_at_front(int x){
    
    if(front == -1 && rear == -1){
        front = rear = 0;
        deque[front] = x;
    }
    else if(front == 0 && rear == N -1){
        printf("The queue is full!");
    }
    else if(front - 1 == rear){
        printf("The queue is full!");
    }
    else if(front == 0 && rear != N-1){
        front = N - 1;
        deque[front] = x;
    }
    else{
        front--;
        deque[front] = x;
    }

}

void dequeue_from_rear(){
    
    if(front == -1 && rear == -1){
        printf("\nThe queue is empty!");
    }
    else if(rear == front){
        printf("\ndequeued element from rear: %d", deque[rear]);
        rear = front = -1;
    }
    else if(rear == 0){
        printf("\ndequeued element from rear: %d", deque[rear]);
        rear = N - 1;
    }
    else{
        printf("\ndequeued element from rear: %d", deque[rear]);
        rear--;
    }

}

void display(){

    if(front == -1 && rear == -1){
        printf("\nThe queue is empty!");
    }
    else{

        int i = front;

        printf("\nCurrent queue: ");
        do{
            printf("%d ", deque[i]);
            i = (i + 1) % N;
        }while(i != (rear + 1) % N);


    }

}

void get_front(){
    if(front == -1 && rear == -1){
        printf("The queue is empty!");
    }
    else{
        printf("\nThe current top element of the deque following FIFO from the front side is: %d", deque[front]);
    }
}

void get_rear(){
    if(front == -1 && rear == -1){
        printf("The queue is empty!");
    }
    else{
        printf("\nThe current top element of the deque following FIFO from the rear side is: %d", deque[rear]);
    }
}


int main(void){

    enqueue_at_front(5);
    enqueue_at_front(7);
    enqueue_at_front(-1);
    display();
    dequeue_from_rear();
    enqueue_at_rear(22);
    enqueue_at_front(25);
    display();
    get_front();
    get_rear();



    return 0;
}