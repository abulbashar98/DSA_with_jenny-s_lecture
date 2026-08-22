#include <stdio.h>

#define N 5

int stack[N];
int top = -1;

// Push
void push(void)
{
    int data;

    if (top >= N - 1)
    {
        printf("Overflow condition! Stack is full.\n");
    }
    else
    {
        printf("Enter data you want to insert in stack: ");
        scanf("%d", &data);

        top++;
        stack[top] = data;

        printf("%d inserted into the stack.\n", data);
    }
}

// Pop
void pop(void)
{
    if (top == -1)
    {
        printf("Underflow condition! Stack is empty.\n");
    }
    else
    {
        int pop_item = stack[top];

        top--;

        printf("%d removed from the stack.\n", pop_item);
    }
}

// Peek
void peek(void)
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display
void display(void)
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("\nStack elements:\n");

        for (int i = top; i >= 0; i--)
        {
            printf("Stack Data: %d\n", stack[i]);
        }
    }
}

int main(void)
{
    int choice;

    do
    {
        printf("\n========== STACK MENU ==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek / Top\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
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

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}