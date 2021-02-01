#include<iostream>
#include<cstdlib>

typedef struct Node //struct
{
    int data;
    struct Node *next; //struct of struct pointer
    struct Node *prev;
}Node_node;

Node_node *head, *tail; //struct pointer

void push(int);
void select(int*);

int main(void){

    using namespace std;
    int datarr[6] = {0};
    time_t *seed;
    srand(time(seed));
    Node_node *head = new Node_node;
    head->data = NULL;
    Node_node *tail = new Node_node;
    tail->data = NULL;
    head->next = tail;
    head->prev = NULL;
    tail->next = NULL;
    tail->prev = head;
  
    for(int i = 0 ; i < 6 ; i++){
       select(&datarr[i]);
       cout << datarr[i] << endl;
       
    }
}

void select(int *arr){
    int ball = rand() % 45 + 1;
    *arr = ball;
}

void push(int data){
    int ball, count;
    int temparr[data];
    Node_node *node = new Node_node;
    Node_node *forward;
    Node_node *back;
    forward = head->next;
    forward->prev = head;
}