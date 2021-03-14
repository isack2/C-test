#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>

typedef struct _Node
{
    char *data = new char;
    _Node *next;
    
}Node;

typedef struct _Stack
{
    _Node *top;

}Stack;

Stack *stack = new Stack;

void push(Stack *, char*);
char *pop(Stack *);
int priority(char*);


int main(void){

    using namespace std;
    char arr1[3] = {'a', 'b', 'c'};
    char arr2[3] = {'d', 'e', 'f'};
    char arr3[3] = {'g', 'h', 'i'};
    push(stack, arr1);
    push(stack, arr2);
    push(stack, arr3);
    cout << pop(stack) << endl;
    cout << pop(stack) << endl;
    cout << pop(stack) << endl;

}

void push(Stack *top, char *chr){

    Node *node = new Node;
    strcpy(node->data, chr);
    node->next = top->top;
    top->top = node;
}

char *pop(Stack *top){

    if(top->top == NULL){

        std::cout << "Underflow" << std::endl;
        return NULL;
    }

    Node *current;
    char *temp = new char;

    current = top->top;
    strcpy(temp, current->data);
    top->top = current->next;
    delete current;
    return temp;
}

int priority(char *ch){

    if((*ch == '+') || (*ch == '-')){
        return 1;
    }
    else if((*ch == '*') || (*ch == '/')){
        return 2;
    }
    else if(*ch == '('){
        return 3;
    }
    else{
        return 0;
    }
}
