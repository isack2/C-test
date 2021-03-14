#include<iostream>
#include<cstdlib>
#define SIZE 5

void push(int *, int);
int pop(int*);
int count = 0;
int first = 0;

int main(void){
    using namespace std;
    int que[SIZE];
    
    push(que, 12);
    push(que, 13);
    push(que, 14);
    cout << pop(que) << endl;
    cout << pop(que) << endl;
    cout << endl;
    cout << pop(que) << endl;
    push(que, 15);
    push(que, 16);
    cout << endl;
    cout << pop(que) << endl;
    cout << endl;
    push(que, 17);
    push(que, 18);
    push(que, 19);
    push(que, 20);
    push(que, 21);
    push(que, 22);
    push(que, 23);
    cout << pop(que) << endl;
    cout << pop(que) << endl;
    cout << pop(que) << endl;
    cout << pop(que) << endl;
    cout << pop(que) << endl;

}

void push(int *pt, int dat){
    if(count > SIZE - 1){
        std::cout << "Overflow" << std::endl;
    }
    else{
        pt[count] = dat;
        count++;
    }
}
int pop(int *pt){
    int temp;
    if(count == 0){
        std::cout << "Underflow";
        return 0;
    }
    else{
        temp = pt[first];
        for(int i = 0 ; i < count - 1 ; i++){
            pt[i] = pt[i+1]; 
        }
        count--;
        return temp;
    }
}
