#include <stdio.h>

#define N 5

int stack_one[N];
int stack_two[N];

int top_one = -1;
int top_two = -1;

int count = 0;

int pop_one_storage = 0;
int pop_two_storage = 0;

void push_to_stack_one(int x){

    if(top_one == N - 1){
        printf("Stack overflow condition");
    }
    else{
        top_one++;
        stack_one[top_one] = x; 
    }

}

void push_to_stack_two(int x){

    if(top_two == N - 1){
        printf("Stack overflow condition!");
    }
    else{
        top_two++;
        stack_two[top_two] = x;
    }

}

void enqueue(int x){

    push_to_stack_one(x);
    count++;

}

int pop_stack_one(){

    if(top_one == -1){
        printf("stack is empty!");
        return -1;
    }
    else{
        return stack_one[top_one--];
    }

}

int pop_stack_two(){

    if(top_two == -1){
        printf("\nstack two is empty!");
        return -1;
    }
    else{
        return stack_two[top_two--];
    }

}

void dequeue(){

    if(top_one == -1 && top_two == -1){
        printf("\nThe queue is empty!");
    }
    else{
        for(int i = 0; i < count; i++){
            pop_one_storage = pop_stack_one();
            push_to_stack_two(pop_one_storage);
        }
        pop_two_storage = pop_stack_two();
        printf("\nDequeued element: %d", pop_two_storage);
        count--;

        for(int j = 0; j < count; j++){
            pop_two_storage = pop_stack_two();
            push_to_stack_one(pop_two_storage);
        }
    
    }

}



void display(){

    if(top_one == -1 && top_two == -1){
        printf("\nThe queue is empty");
    }

    else{

        for(int i = top_one; i >= 0 ; i--){
            pop_one_storage = pop_stack_one();
            push_to_stack_two(pop_one_storage);
        }
        
        printf("\nCurrent Queue: ");
        for(int j = top_two; j >= 0 ; j--){
            pop_two_storage = pop_stack_two();
            printf("%d ", pop_two_storage);
            push_to_stack_one(pop_two_storage);
        }

    }

}





int main(void){

    enqueue(5);
    enqueue(7);
    enqueue(9);
    display();
    dequeue();
    display();


    return 0;
}