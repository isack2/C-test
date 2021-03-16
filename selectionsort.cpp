#include<iostream>

void swap(int *, int *);
void selsort(int *, int);

int main(void){
    using namespace std;
    int size;
    
    cout << "size: ";
    cin >> size;

    int array[size];

    cout << "input array: ";
    for(int i = 0 ; i < size ; i++){
        cin >> array[i];
    }

    cout << "input array: ";
    for(int i = 0 ; i < size ; i++){
        cout << array[i] << " ";
    }

    cout << endl;

    selsort(array, size);
    
    cout << "selectsort array: ";
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

void selsort(int *arr, int sortsize){
    int min, index;

    for(int i = 0 ; i < sortsize ; i++){
        min = arr[i];
        index = 0;
        for(int j = i + 1 ; j < sortsize ; j++){
            if(min > arr[j]){
                min = arr[j];
                index = j;
            }
        }
        if(min != arr[i]){
            swap(&arr[i], &arr[index]);
        }
    }
}
