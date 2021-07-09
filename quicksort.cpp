#include<iostream>
using namespace std;

void swap(int *, int*);
void quicksort(int *, int);

int main(void){
    int size;

    cin >> size;
    int *array = new int[size];

    for(int i = 0 ; i < size ; i++){
        cin >> array[i];
    }
    cout << "input : ";
    for(int i = 0 ; i < size ; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "quicksort: ";
    quicksort(array, size);
    for(int i = 0 ; i < size ; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    delete [] array;
}

void swap(int *sel1, int *sel2){
    int temp = *sel1;
    *sel1 = *sel2;
    *sel2 = temp;
}

void quicksort(int *arr, int size){
    int rear = size - 1;
    int front = 1;

    if(size <= 1){
        return;
    }

    while(front <= rear){
        while(arr[0] > arr[front] && front < size - 1){
            front++;
        }
        while(arr[0] < arr[rear] && rear > 0){
            rear--;
        }
        if(front < rear && arr[front] > arr[rear]){
            swap(&arr[front], &arr[rear]);
        }
        else{
            swap(&arr[0], &arr[rear]);
            quicksort(arr, rear);
            quicksort(arr + rear + 1, size - rear - 1);
        }
    }
}