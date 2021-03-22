#include<iostream>

void quicksort(int *, int);
void swap(int *, int *);
int count = 0;

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

    while(left <= right){
        while((left < right) && (left < size - 1)){
            while((arr[left] < arr[pivot]) && (left < size - 1)){
                left++;
                }
            while((arr[right] > arr[pivot]) && (right > 0)){
                right--;
                }
            if((left >= right) && (arr[0] > arr[right])){
                swap(&arr[0], &arr[right]);
                break;
                }
            else{
                swap(&arr[left], &arr[right]);
                }
            }
        }
        quicksort(arr, right);
        quicksort(arr + right + 1, size - right - 1);
        }

// 1 2 9 6 4 (left = 1, arr[left] = 2 , right = 0, arr[right] = 1, arr[pivot] = 1)
// 1 2 9 6 4
// 1 2 9 6 4
// 1 2 4 6 9

// 5 7 3 9 2
// 5 2 3 9 7
// 3 2 5 9 7 (1st)
// 2 3 5 9 7 
// 2 3 5 7 9


// 9 1 3 6 7 (left = 4, right = 4, arr[left] = 7, arr[right] = 7, arr[pivot] = 9)
// 7 1 3 6 9 
// 6 1 3 7 9
// 3 1 6 7 9
// 1 3 6 7 9



// 2 9 1 6 4
// 2 1 9 6 4 (left = 9 , right = 1) 
// 1 2 9 6 4 

