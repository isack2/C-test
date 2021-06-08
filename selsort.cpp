#include<iostream>
#include<limits>
using namespace std;

void swap(int *, int *);
void selsort(int *, int);

int main(void){
    int size;

    cin >> size;
    int *arr = new int[size];
 
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }
    selsort(arr, size);
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }

    delete [] arr;
}

void swap(int *origin, int *transe){
    int temp;
    temp = *origin;
    *origin = *transe;
    *transe = temp; 
}

void selsort(int *arr, int size){
    int maxvalue;
    int *tempadress = new int;

    for(int i = 0 ; i < size ; i++){
        maxvalue = INT_MAX;
        for(int j = i ; j < size ; j++){
            if(maxvalue > arr[j]){
                maxvalue = arr[j];
                tempadress = &arr[j];
                }
        }
        swap(&arr[i], tempadress);
    }
}