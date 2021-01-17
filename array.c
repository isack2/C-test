#include<stdlib.h>
#include<stdio.h>

int main(void){

    int row, col;
    int **array;

    printf("input row : \n");
    scanf("%d", &row);
    getchar();
    
    printf("input col : \n");
    scanf("%d", &col);
    getchar();

    array = malloc(sizeof(int*)*row);
    for(int i = 0 ; i < row ; i++){
        array[i] = malloc(sizeof(int)*col);
    }

    for(int n = 0 ; n < row ; n++){
        for(int m = 0 ; m < col ; m++){
            printf("input (%d,%d) number : ", (n+1), (m+1));
            scanf("%d", &array[n][m]);
            getchar();
            }
    }

    printf("array is : \n");

    for(int n = 0 ; n < row ; n++){
        for(int m = 0 ; m < col ; m++){
            printf(" %d ", array[n][m]);
            }
            printf("\n");
    }

     for(int x = 0 ; x < col ; x++){
        free(array[x]);
    }

    free(array);
    
}