#include <stdio.h>

#define N 5
int stack[N];
int top = -1;

void push(top){
    int data = 0;
    printf("enter data you want to insert in stack!");
    scanf("%d", &data);

    if(top == N - 1){
        printf("Overflow condition!");
    }
    else{
        top++;
        stack[top] = data;
    }

}

void pop(){

    if(top == -1){
        printf("underflow condition! or the current Stack is empty!");
    }
    else{
        int pop_item;
        pop_item = stack[top];
        top--;
        print(pop_item);
    }

}

void peek(){

    if(top == -1){
        printf("list is empty!");
    }
    else{
        print(stack[top]);
    }

}

void display(){
    if(top == -1){
        printf("Underflow condition!");
    }
    else{
        for(int i = top; i >= 0; i--){
            printf("Stack Data: %d\n", stack[top]);
        }
    }
}


int main(void){

    int choice = 0;
    printf("Enter your choice 1.Push 2.Pop 3.Peek/top and 4.Display");
    scanf("%d", &choice);

    switch (choice){
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        peek();
        break;
    case 4:
        display();
        break;
    default:
        printf("invalid choice");
    }
    
    while(choice != 0){
        getch();
    }

    return 0;
}