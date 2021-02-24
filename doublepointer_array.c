#include<stdio.h>
#include<stdlib.h>

int main(void){

   int **dptr = (int**)malloc(sizeof(int*)*5);

   for(int i = 0 ; i < 5 ; i++){
       dptr[i] = (int*)malloc(sizeof(int)*3);
   }

   for(int i = 0 ; i < 5 ; i++){
       for(int j = 0 ; j < 3 ; j++){
           scanf("%d", &dptr[i][j]);
       }
   }

   for(int i = 0 ; i < 5 ; i++){
       for(int j = 0 ; j < 3 ; j++){
           printf("%d", dptr[i][j]);
       }
       printf("\n");
   }

   for(int i = 0 ; i < 5 ; i++){
       free(dptr[i]);
   }
   free(dptr);
}