#include<iostream>
#include<cstdlib>

typedef struct _Node
{
    int data;
    _Node *next;

}Node;

typedef struct _Que
{
    Node *first;
    Node *last;

}Que;

Que *que = new Que;

void push(Que *, int);
int pop(Que *);

int main(void){

    using namespace std;
    
    push(que, 123);
    push(que, 456);
    cout << pop(que) << endl;
    cout << pop(que) << endl;

    delete que;
    
}

void push(Que *que, int dat){

    if(que->last->next == NULL){
        Node *node = new Node;

        node->data = dat;
        node = que->first;
        que->last->next = que->first;
    }
    else if(que->last->next == que->first){
        Node *node1 = new Node;

        node1->data = dat;
        node1 = que->last;
    }
    else{
        Node *node2 = new Node;

        node2->data = dat;
        node2->next = que->last;
        que->last = node2;
        }
    }

int pop(Que *que){

    Node *current = new Node;
    current = que->first;
    int temp;


    if(current == NULL){
        std::cout << "Underflow" << std::endl;
        return NULL;
    }
    else{
        Node *prev = new Node;
        
        temp = current->data;
        prev = que->first;
        que->first->next = prev;
        delete prev;
        return temp;
    }
}
