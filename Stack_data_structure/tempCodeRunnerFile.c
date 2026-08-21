#include <stdio.h>
#include <stdlib.h>

#define FIRST_PRECEDENCE 4
#define SECOND_PRECEDENCE 3
#define THIRD_PRECEDENCE 2
#define FOURTH_PRECEDENCE 1

#define LEFT_TO_RIGHT_ASSOCIATIVITY 1
#define RIGHT_TO_LEFT_ASSOCIATIVITY -1


int set_precedence = 0;

int set_associativity = 0;

char top;


char infix_expression[50] = {
    'K','+','L','-','M','*','N','+','(','O','^','P',')',
    '*','W','/','U','/','V','*','T','+','Q','\0'
};

/* char infix_expression[50] = "k+L-M*N+(O^P)*W/U/V*T+Q"; */

char converted_postfix_expression[50] = "";

char stack[25] = "";

int stack_length = 0;



void push_to_converted_postfix_expression(char data)
{
    int i = 0;

    while(converted_postfix_expression[i] != '\0'){
        i++;
    }

    converted_postfix_expression[i] = data;

    /* FIX: terminate the string */
    converted_postfix_expression[i + 1] = '\0';

    printf("Current converted postfix expression: ");

    for(int j = 0; j <= i; j++){
        printf("%c", converted_postfix_expression[j]);
    }

    printf("\n");
}


int find_current_stack_length()
{
    int j = 0;

    int stack_length = 0;

    while(stack[j] != '\0'){
        stack_length++;
        j++;
    }

    printf("\nCurrent stack length: %d", stack_length);

    return stack_length;
}


void push_to_stack(char data)
{
    int i = 0;

    while(stack[i] != '\0'){
        i++;
    }

    stack[i] = data;

    /* FIX: terminate stack string */
    stack[i + 1] = '\0';

    stack_length = find_current_stack_length();

    printf("\nCurrent Stack: ");

    for(int k = 0; k < stack_length; k++){
        printf("%c ", stack[k]);
    }

    printf("\n");
}


char pop()
{
    int i = 0;

    while(stack[i] != '\0'){
        i++;
    }

    if(i == 0){
        return '\0';
    }

    char data = stack[i - 1];

    stack[i - 1] = '\0';

    printf("\ncurrent stack: ");

    int k = 0;

    while(stack[k] != '\0'){
        printf("%c", stack[k]);
        k++;
    }

    printf("\n");

    return data;
}


char find_top()
{
    int i = 0;

    while(stack[i] != '\0'){
        i++;
    }

    /* FIX: don't access stack[-1] */
    if(i == 0){
        return '\0';
    }

    return stack[i - 1];
}



int main(void)
{
    /* char infix_expression[50] = "k+L-M*N+(O^P)*W/U/V*T+Q"; */

    size_t length_of_infix_expression = 0;

    int i = 0;

    while(infix_expression[i] != '\0'){
        printf("%c", infix_expression[i]);
        i++;
    }

    length_of_infix_expression = i;

    printf("\n");

    printf("%d", i);

    printf("\n");


    for(int j = 0; j < length_of_infix_expression; j++){

        if((infix_expression[j] >= 65) &&
           (infix_expression[j] <= 90)){

            printf("Capital letter: %c\n", infix_expression[j]);

            push_to_converted_postfix_expression(infix_expression[j]);
        }


        else if(infix_expression[j] == 40 ||
                infix_expression[j] == 41){

            set_precedence = FIRST_PRECEDENCE;

            if(infix_expression[j] == 40){

                printf("left-parenthesis.\n");

                push_to_stack(infix_expression[j]);
            }

            else{

                printf("right-parenthesis.\n");

                stack_length = find_current_stack_length();

                printf("\nCurrent stack length:  %d",
                       stack_length);

                int k = 1;

                while(stack[stack_length - k] != 40){

                    /* FIX: pop the operator and add it
                       to postfix */
                    char popped_data = pop();

                    push_to_converted_postfix_expression(
                        popped_data
                    );

                    stack_length = find_current_stack_length();

                    k = 1;
                }

                /* Remove '(' */
                pop();

                stack_length = find_current_stack_length();

                printf("\nCurrent stack length:  %d",
                       stack_length);
            }
        }


        else if(infix_expression[j] == 94){

            set_precedence = SECOND_PRECEDENCE;

            set_associativity = RIGHT_TO_LEFT_ASSOCIATIVITY;

            top = find_top();

            printf("TOP: %c\n", top);

            /*
             * Since ^ is right associative:
             *
             * Pop only operators having HIGHER precedence.
             * Do not pop another ^ with equal precedence.
             */
            while(top != '\0' &&
                  top != '(' &&
                  top != ')' &&
                  (
                      (top == '*' || top == '/') ||
                      (top == '+' || top == '-')
                  )){

                char popped_data = pop();

                push_to_converted_postfix_expression(
                    popped_data
                );

                top = find_top();
            }

            push_to_stack(infix_expression[j]);

            printf("exponent.\n");
        }


        else if(infix_expression[j] == 42 ||
                infix_expression[j] == 47){

            set_precedence = THIRD_PRECEDENCE;

            set_associativity = LEFT_TO_RIGHT_ASSOCIATIVITY;

            /*
             * * and / are left associative.
             *
             * Pop operators having higher OR equal
             * precedence.
             */
            top = find_top();

            while(top != '\0' &&
                  top != '(' &&
                  top != ')' &&
                  (
                      top == '^' ||
                      top == '*' ||
                      top == '/'
                  )){

                char popped_data = pop();

                push_to_converted_postfix_expression(
                    popped_data
                );

                top = find_top();
            }

            push_to_stack(infix_expression[j]);

            if(infix_expression[j] == 42){

                printf("multiplication.\n");
            }

            else{

                printf("division.\n");
            }
        }


        else if(infix_expression[j] == 43 ||
                infix_expression[j] == 45){

            set_precedence = FOURTH_PRECEDENCE;

            set_associativity = LEFT_TO_RIGHT_ASSOCIATIVITY;

            /*
             * + and - are left associative.
             *
             * Pop every operator above them except '('.
             */
            top = find_top();

            while(top != '\0' &&
                  top != '(' &&
                  top != ')'){

                char popped_data = pop();

                push_to_converted_postfix_expression(
                    popped_data
                );

                top = find_top();
            }

            push_to_stack(infix_expression[j]);

            if(infix_expression[j] == 43){

                printf("plus.\n");
            }

            else{

                printf("minus.\n");
            }
        }
    }


    /*
     * FIX:
     * After the complete infix expression has been processed,
     * pop all remaining operators from the stack.
     */
    while(find_top() != '\0'){

        char popped_data = pop();

        push_to_converted_postfix_expression(
            popped_data
        );
    }


    printf("\n\nFinal postfix expression: %s\n",
           converted_postfix_expression);


    return 0;
}