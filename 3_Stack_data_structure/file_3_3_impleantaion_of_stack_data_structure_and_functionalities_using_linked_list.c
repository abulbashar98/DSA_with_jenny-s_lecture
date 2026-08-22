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
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int data;
            printf("Enter data you want to insert in stack: ");
            scanf("%d", &data);
            push(data);
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
            getch();
            break;    

        default:
            getch();
            printf("Invalid choice! try again.\n");

        }
    
    }while(choice != 0);

    

    return 0;
}
