#include<iostream>
#include<cstdbool>
#include<cstdlib>

using namespace std;

typedef struct _Node{
    char *data = new char;
    _Node *next = NULL;
}Node;

typedef struct _Stack{
    Node *top = NULL;
}Stack;

void push(char *, Stack *);
char *pop(Stack *);


int main(void){
    Stack *stack;
    char *sizebucket = new char;
    char **dstr = new char*[10];
    for(int i = 0 ; i < 10 ; i++){
        dstr[i] = new char;
    }
    for(int i = 0 ; i < 10 ; i++){
        delete [] dstr[i];
    }
    delete [] dstr;
}

void push(char *str, Stack *stack){
    Node *node = new Node;
    strcpy(node->data, str);
    if(stack->top == NULL){
        stack->top = node;
    }
    else{
        node->next = stack->top;
        stack->top = node;
    }
}

char *pop(Stack *stack){
    char *tempchar = new char;
    Node *temp = new Node;
    if(stack->top == NULL){
        cout << "empty" << endl;
        return 0;
    }
    else{
        strcpy(tempchar, stack->top->data);
        temp = stack->top;
        stack->top = stack->top->next;
        delete temp;
        return tempchar;
    } 
}