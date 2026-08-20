#include <stdio.h>

char expression[50] = {'K','+','L','-','M','*','N','+','(','O','^','P',')','*','W','/','U','/','V','*','T','+','Q','\0'};

// char expression[50] = "k+L-M*N+(O^P)*W/U/V*T+Q";

char stack[25] = {};

void push(char data){
    
    int i = 0;
    
    while(stack[i] != '\0'){
        i++;
    }

    stack[i] = data;
    
    int j = 0;
    int stack_length = 0;
    while(stack[j] != '\0'){
        stack_length++;
        j++;
    }
    printf("\nCurrent stack length: %d", stack_length);

    
    
    printf("\nCurrent Stack: ");

    for(int k = 0; k < stack_length; k++){
        printf("%c ", stack[k]);
    }
    printf("\n");

}




int main(void){

  

    // char expression[50] = "k+L-M*N+(O^P)*W/U/V*T+Q";

    size_t length_of_expression = 0;

    int i = 0;

    while(expression[i] != '\0'){
        printf("%c", expression[i]);
        i++;
    }

    length_of_expression = i;    
    printf("\n");
    printf("%d", i);

    printf("\n");

    for(int j = 0; j < length_of_expression; j++){

        if((expression[j] >= 65) && (expression[j] <= 90)){
            printf("Capital letter: %c\n", expression[j]);
            push(expression[j]);
        }
        else if(expression[j] == 40 || expression[j] == 41){
            if(expression[j] == 40){
                printf("left-parenthesis.\n");
            }
            else{
                printf("right-parenthesis.\n");
            }

        }
        else if(expression[j] == 94){
            printf("exponent.\n");
        }
        else if(expression[j] == 42 || expression[j] == 47){
            if(expression[j] == 42){
                printf("multiplication.\n");
            }
            else{
                printf("division.\n");
            }
        }
        else if(expression[j] == 43 || expression[j] == 45){
            if(expression[j] == 43){
                printf("plus.\n");
            }
            else{
                printf("minus.\n");
            }
        }


    }



    // printf("%d", length_of_expression);

    return 0;
}