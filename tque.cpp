#include<iostream>
#include<cstdlib>

typedef struct _Node
{
    int data;
    _Node *next;

}Node;

typedef struct _Que
{
    _Node *last;
    _Node *first;
    int count;
}Que;

Que *que = new Que;

void push(Que *, int);
int pop(Que *);

int main(void){
    using namespace std;
    que->count = 0;

    cout << pop(que) << endl;
    push(que, 123);
    push(que, 456);
    push(que, 789);
    push(que, 12344);
    push(que, 666676);
    cout << pop(que) << endl;
    cout << pop(que) << endl;
    cout << pop(que) << endl;
    cout << pop(que) << endl;
    cout << pop(que) << endl;
    cout << pop(que) << endl;
    
}

void push(Que *q, int dat){
    Node *node = new Node;

    if(q->count == 0){
        node->data = dat;
        q->first = node;
        q->first->next = 0;
        q->count++;
    }
    else if(q->count == 1){
        node->data = dat;
        q->last = node;
        node->next = q->first;
        q->count++;
    }
    else{
        node->data = dat;
        node->next = q->last;
        q->last = node;
        q->count++;
    }
}

int pop(Que *q){
    Node *temp;
    Node *current = q->last;
    int tempdat;

    if(q->count == 0){
        std::cout << "Underflow";
        return 0;
    }
    else if(q->count == 1){
        temp = q->first;
        tempdat = temp->data;
        q->first = 0;
        q->count--;
        return tempdat;
    }
    else{
        while(current->next != q->first){
            current = current->next;
        }
        temp = q->first;
        tempdat = temp->data;
        q->first = current;
        q->count--;
        return tempdat;
    }
}