#include <stdio.h>

int main(void){
    
    int a[50];
    int size;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    if(size > 0 && size <= 50){
        printf("Enter Elements of array.\n");
        for(int i = 0; i < size; i++){
            printf("Element%d: ", i + 1);
            scanf("%d",&a[i]);
        }

        printf("Your array is: {");
        for(int j = 0; j < size; j++){
            if(j < size - 1){
                printf("%d,", a[j]);
            }
            else{
                printf("%d}", a[j]);
            }
        }

    }

    else{
        printf("Overflow condition, size can't be 0, less than 0 or greater than 50");
    }


    //******* Array Operation Deletion
    
    int pos;
    int deleted_item;

    printf("\nEnter the position you want to delete data from: ");
    scanf("%d", &pos);

    // For unsorted array best algorithm will be to take the element from last position and put that value to the position from where data was deleted. In that case TIME COMPLEXITY will be O(1)

    // a[pos - 1] = a[size - 1];
    // size--;

    // print new unsorted array:
    
    // printf("Your new unsorted array is: {");

    // for(int k = 0; k < size; k++){
    //    if(k < size - 1){
    //             printf("%d,", a[k]);
    //         }
    //         else{
    //             printf("%d}", a[k]);
    //         }
    // }


    //*****  For sorted array we shift items one by one to position - 1. When the deletion position is random. If the deletion position is at the end, we just decrease the array size by 1. That should delete the last index value. in this case TIME COMPLEXITY again depends on position to delete data from. Last position TIME COMPLEXITY is always O(1). Random position TIME COMPLEXITY is O(n) or O(n-p)
    
    // Last pos for sorted array
    if(pos == size){
        deleted_item = a[pos -1];
        size--;
    }
    
     
    

    // random pos for sorted array
    else if(pos > 1 && pos < size){
        deleted_item =  a[pos -1];

        for(int i = pos - 1; i < size - 1; i++){
            a[i] = a[i+1];
        }
        size--;
    }

    else if(pos == 1){

        deleted_item =  a[pos -1];

        for(int i = 0; i < size - 1; i++){
            a[i] = a[i+1];
        }
        size--;

    }
    
    

    
    printf("Your new sorted array is: {");

    for(int k = 0; k < size; k++){
       if(k < size - 1){
                printf("%d,", a[k]);
            }
            else{
                printf("%d}\n", a[k]);
            }
    }

    printf("Deleted Value: %d", deleted_item);






    return 0;
}