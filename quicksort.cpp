#include<iostream>

void quicksort(int *, int);
void swap(int *, int *);

int main(void){
    using namespace std;
    int size;

    cout << "Size: ";
    cin >> size;
    cout << "array: ";

    int array[size];

    for(int i = 0 ; i < size ; i++){
        cin >> array[i];
    }
    cout << "array is: " << " ";
    for(int i = 0 ; i < size ; i++){
        cout << array[i] << " ";
    }
    
    quicksort(array, size);
    cout << "sorted array: ";
    for(int i = 0 ; i < size ; i++){
        cout << array[i] << " ";
    }
}

void swap(int *a, int *b){
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int *arr, int size){
    int left, right, pivot;
    
    pivot = 0;
    right = size - 1;
    left = pivot + 1;

    if(size <= 1){
        return;
    }
    while(size > 1){
        while((arr[left] < arr[pivot]) && (left < size - 1)){
            left++;
            }
        while((arr[right] > arr[pivot]) && (right > pivot)){
            right--;
            }
        if((left >= right) && (arr[pivot] >= arr[right])){
            swap(&arr[pivot], &arr[right]);
            pivot = right;
            break;
            }
        else{
            swap(&arr[left], &arr[right]);
            }
    }   
    quicksort(arr, pivot);
    quicksort(&arr[pivot] + 1, size - pivot - 1);
}