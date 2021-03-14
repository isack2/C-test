#include<iostream>
#include<string>
#include<cstdlib>
#define MAX 3

typedef struct Node{

    std::string data;
    Node *next;

}stack;

stack *top = new stack;

void push(std::string);
std::string pop(void);

int main(void){

    using namespace std;

    push("1231234");
    push("adfae1231");
    push("1231246234");
    push("ade1231sdaf");
    push("1234");
    push("adfae123151  sdaf34");
    cout << pop() << endl;
    push("adfadfafe 123514");
    cout << pop() << endl;
    cout << pop() << endl;
    push("123124566234");
    push("adfae123151  sdaf34");

    cout << pop();
    cout << endl;
    cout << pop();
    cout << endl;
    cout << pop();
    cout << endl;

}

void push(std::string str){
    
    int cot = 0;
    stack *count = top;
    stack *node = new stack;

    if(cot != MAX){
        count = count->next;
        cot++;
        node->data = str;
        node->next = top;
        top = node;
    }
    else{
        std::cout << "Max data" << std::endl;
    }
}


std::string pop(void){

    stack *current = new stack;
    current = top;
    std::string data = current->data;

    if(top->next == NULL){
        std::cout << "No data" << std::endl;
    }
    else{
        top = current->next;
        delete current;
    }
    return data;
}

