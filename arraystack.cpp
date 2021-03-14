#include<iostream>
#define SIZE 8
#define INF 99999999999

void push(int);
int pop(void);

int array[SIZE];
int top;

int main(void){

    using namespace std;
    top = -1;

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
}

void push(int data){

    if(top > SIZE -1){
        std::cout << "overflow: ";
        std::cout << INF << std::endl;
    }
    else{
        top++;
        array[top] = data;
    }
}

int pop(void){

    int data;

    if((top) == -1){
        std::cout << "underflow" << std::endl;
        std::cout << INF << std::endl;
    }
    else{
        data = array[top];
        top--;
    }
    return data;
}
