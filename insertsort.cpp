#include<iostream>
using namespace std;

void swap(int *, int *);
void insertsort(int *, int);

int main(void){
    int size;
    
    cin >> size;
    int *arr = new int[size];
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }
    insertsort(arr, size);
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *origin, int *transe){
    int temp;
    temp = *origin;
    *origin = *transe;
    *transe = temp;
}

void insertsort(int *arr, int size){
    int j;
    for(int i = 0 ; i < size - 1 ; i++){
        j = i;
        while(j >= 0 && arr[j] > arr[j+1]){
            swap(&arr[j], &arr[j+1]);
            j--;
        }
    }
}