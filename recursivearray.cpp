#include<iostream>

void printarray(int *, int);

int main(void){
    using namespace std;

    int array[5] = {1, 2, 3, 4, 5};
    printarray(array, 5);
}

void printarray(int *arr, int size){
    int temp, count, i;
    count = 0;
    i = 0;

    if(size == 0){
        return;
    }
    while(i < size){
        std::cout << arr[i] << " ";
        i++;
    }
    std::cout << std::endl;
    temp = size - 1;
    count++;
    printarray(&arr[0]+count, temp);
}
    