#include<iostream>

void swap(int *, int *);
void insort(int *, int);

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
    cout << "input array: ";
    for(int i = 0 ; i < size ; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "insertionsort: ";
    insort(array, size);
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

void insort(int *arr, int val){
    for(int i = 0 ; i < val ; i++){
        int target = arr[i];
        for(int j = i + 1 ; j < val ; j++){
            if(target > arr[j]){
                swap(&arr[i], &arr[j]);
                target = arr[i];
            }
        }
    }
}
