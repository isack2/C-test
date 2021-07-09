#include<iostream>
using namespace std;
#define MAXSIZE  10000

void swap(int *, int *);

typedef struct _Pque{
    int index = 0;
    int array[MAXSIZE] = {};
}Pque; 

void insert(Pque *, int);
void pop(Pque *);

int main(void){
    Pque *heap = new Pque;
    insert(heap, 10);
    insert(heap, 8);
    insert(heap, 6);
    insert(heap, 9);
    insert(heap, 24);
    insert(heap, 12);
    insert(heap, 3);
    insert(heap, 5);
    insert(heap, 1);
    pop(heap);
    pop(heap);
    pop(heap);
    pop(heap);
    pop(heap);
    pop(heap);
    pop(heap);
    pop(heap);
    pop(heap);
    pop(heap);
    pop(heap);

}

void swap(int *target, int *now){
    int temp = *target;
    *target = *now;
    *now = *target;
}

void insert(Pque *heap, int data){
    int current = heap->index;
    int parrent = (current - 1) / 2;

    if(current <= MAXSIZE){
        heap->array[current] = data;
        while(heap->array[current] > heap->array[parrent] && parrent >= 0){
            swap(heap->array[current], heap->array[parrent]);
            current = parrent;
            parrent = (current - 1) / 2;
        }
        (heap->index)++;;
    }
    else{
        cout << "Over Flow!" << endl;
    }
}

void pop(Pque *heap){
    if(heap->index <= 0){
        cout << "Empty!" << endl;
    }
    else{
        int current = 0;
        int left = 1;
        int right = 2;
        int temp = heap->array[0];
        (heap->index)--;
        heap->array[0] = heap->array[heap->index];
        if(heap->index != '\0'){
            heap->array[heap->index] = '\0';
        }
        while(current < heap->index){
            if(heap->array[current] < heap->array[left] && heap->array[left] > heap->array[right]){
                swap(heap->array[current], heap->array[left]);
                current = left;
                left = current * 2 + 1;
                right = current * 2 + 2;
            }
            else if(heap->array[current] < heap->array[right] && right <= heap->index){
                swap(heap->array[current], heap->array[right]);
                current = right;
                left = current * 2 + 1;
                right = current * 2 + 2;
            }
            else
                break;
        }
        cout << temp << endl;
    }
}