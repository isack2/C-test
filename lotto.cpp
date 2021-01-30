#include<iostream>
#include<cstdlib>

typedef struct node
{
    int data;
    int *next;
    int *prev;
}nodes;

nodes *head, *tail, *node;

void push(int*);
void testing(void);
void select(int*);

int main(void){

    using namespace std;
    int datarr[6] = {0};
    time_t *seed;
    srand(time(seed));
    nodes *head = new nodes;
    head->data = 0;

    nodes *tail = new nodes;
    nodes *node = new nodes;
  
    for(int i = 0 ; i < 6 ; i++){
       select(&datarr[i]);
       cout << datarr[i] << endl;
       
    }
}

void select(int *arr){
    int ball = rand() % 45 + 1;
    *arr = ball;
}

void push(int *arr){
}