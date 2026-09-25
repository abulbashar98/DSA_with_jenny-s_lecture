#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
    int data;
    struct node *link;
};

struct node *top = NULL;


void push(int data){

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    newnode->data = data;
    newnode->link = top;
    top = newnode;
    printf("You inserted %d in stack.", top->data);

}

void pop(){

    if(top == NULL){
        printf("Stack is empty!");
    }
    else{
        struct node *temp;
        temp = top;
        printf("Item deleted from the top is: %d", temp->data);

        top = temp->link;
        free(temp);

    }

}

void peek(){

    if(top == NULL){
        printf("Stack is empty!");
    }
    else{
        printf("Top item from the stack is: %d", top->data);
    }

}

void display(){

    if(top == NULL){
        printf("Stack is empty!");
    }
    else{
        struct node *temp;

        temp = top;

        printf("Stack Elements: \n");
        do{
            printf("Stack Data: %d\n", temp->data);
            temp = temp->link;
        }while(temp != NULL);

    }

}


int main(){

    int choice;
    

    do{
        printf("\n*****Stack_Menu********\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("0.Exit the programme.\n");

        printf("Enter your choice: ");
        while(scanf("%d", &choice) != 1){
            printf("Invalid choice!\n");
            char buffer;
            while((buffer = getchar()) != '\n' && buffer != EOF){
                printf("Found this in buffer: %c\nEnter your choice again: ");
            }
        }

        switch (choice)
        {
        case 1:
            int data;
            printf("Enter data you want to insert in stack: ");
            if(scanf("%d", &data) != 1){
                printf("Invalid data!\n");
                while(scanf("%d", &data) != 1){
                    char buffer;
                    while((buffer = getchar()) != '\n' && buffer != EOF){
                        printf("Found this in buffer: %c\nPlease provide a valid integer: ", buffer);
                    }
                }
            }
            else{
                push(data);
            }
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
        case 0:
            printf("Quitting....");
            break;    

        default:
            printf("Invalid choice! try again.\n");

        }
    
    }while(choice != 0);

    

    return 0;
}
