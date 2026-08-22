#include <stdio.h>

int main(void){

    // two dimensional array compile time declaration;

    int a[][3] = {4,5,6,7,1,5};

    printf("%d\n", a[0][0]);
    printf("%d\n", a[1][1]);

    /*
      terminal: 4
                1
    */

    int b[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    printf("%d\n", b[2][0]);
    printf("%d\n", b[1][2]);
    /*
      terminal: 9
                7
    */

    // two dimensional array runtime declaration (row major)
    
    #define ROW_SIZE_r 3
    #define COLUMN_SIZE_r 4

    int r[ROW_SIZE_r][COLUMN_SIZE_r];
    
    printf("Enter elements for this two dimensional array named c. Notice that the array is 'ROW major', we have 3 rows and four columns for each row. So, total number of elements are 12. Total size of array is 12 * 4 = 48 bytes.\n");

    for(int i = 0; i < ROW_SIZE_r; i++){
        for(int j = 0; j < COLUMN_SIZE_r; j++){
            printf("Element-r[%d][%d]: ", i, j);
            scanf("%d", &r[i][j]);
        }
    }

    for(int k = 0; k < ROW_SIZE_r; k++){
        printf("{");
        for(int l = 0; l < COLUMN_SIZE_r; l++){
            
            if(l < COLUMN_SIZE_r - 1){
                printf("%d,", r[k][l]);
            }

            else if(l == COLUMN_SIZE_r - 1 && k < ROW_SIZE_r - 1){
                printf("%d},", r[k][l]);
            }

            else if(l == COLUMN_SIZE_r - 1 && k == ROW_SIZE_r - 1){
                printf("%d}", r[k][l]);
            }
        }
    }
    
    /*
        terminal: {1,2,3,4},{5,6,7,8},{9,10,11,12}
    */



    // two dimensional array runtime declaration (column major)
    
    #define COLUMN_SIZE_c 4
    #define ROW_SIZE_c 5

    int c[COLUMN_SIZE_c][ROW_SIZE_c];
    
    printf("\nEnter elements for this two dimensional array named c. Notice that the array is 'COLUMN major', we have 3 columns and 4 rows for each column. So, total number of elements are 12. Total size of array is 12 * 4 = 48 bytes.\n");

    for(int i = 0; i < COLUMN_SIZE_c; i++){
        for(int j = 0; j < ROW_SIZE_c; j++){
            printf("Element-c[%d][%d]: ", i, j);
            scanf("%d", &c[i][j]);
        }
    }

    for(int k = 0; k < COLUMN_SIZE_c; k++){
        printf("{");
        for(int l = 0; l < ROW_SIZE_c; l++){
            
            if(l < ROW_SIZE_c - 1){
                printf("%d,", c[k][l]);
            }

            else if(l == ROW_SIZE_c - 1 && k < COLUMN_SIZE_c - 1){
                printf("%d},", c[k][l]);
            }

            else if(l == ROW_SIZE_c - 1 && k == COLUMN_SIZE_c - 1){
                printf("%d}", c[k][l]);
            }
        }
    }
    
    /*
        terminal: {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}
    */



    return 0;
}