#include<iostream>
using namespace std;

typedef struct _Node{
    char *name;
    int data = 0;
    _Node *next = nullptr; 
}Node;

int main(void){
    Node *pstruct = new Node;

    pstruct->data = 0; // pstruct[0].data = 0
    (pstruct + 1)->data = 1;
    (pstruct + 2)->data = 2;
    pstruct[3].data = 3;
    pstruct[4].data = 4;
    
    cout << "pstruct" << endl;
    for(int i = 0 ; i < 4 ; i++){
        cout << "adress: " << pstruct + i << ", " << "value: " << (pstruct+i)->data << endl;
    }
    cout << endl;

    Node **dpstruct = new Node*[10];
    for(int i = 0 ; i < 10 ; i++){
        dpstruct[i] = new Node;
    }
    delete pstruct;

    dpstruct[0]->data = 0; //dpstruct[0][0].data = 0
    dpstruct[0][1].data = 1;
    dpstruct[1]->data = 10; // dpstruct[1][0].data = 1
    dpstruct[1][0].data = 12;
    dpstruct[1][1].data = 11;
    dpstruct[0][2].data = 2;
    dpstruct[2]->data = 20;
    (dpstruct + 1)[3]->data = 13; // dpstruct[3][3].data = 13

    cout << "dpstruct" << endl;
    cout << "address: " << dpstruct << ", " << "value : " << dpstruct[0][0].data << endl;
    cout << "address: " << ((dpstruct) + 1) << ", " << "value : " << dpstruct[0][1].data << endl;
    cout << "address: " << ((dpstruct + 1)) << ", " << "value : " << dpstruct[1]->data << endl;
    cout << "address: " << ((dpstruct + 0) + 1) << ", " << "value : " << dpstruct[1][0].data << endl;
    cout << "address: " << ((dpstruct + 1) + 1) << ", " << "value : " << dpstruct[1][1].data << endl;
    cout << "address: " << ((dpstruct + 1) + 1) << ", " << "value : " << (dpstruct + 1)[1]->data << endl;
    cout << "address: " << ((dpstruct) + 2) << ", " << "value : " << dpstruct[0][2].data << endl;
    cout << "address: " << ((dpstruct + 2)) << ", " << "value : " << dpstruct[2][0].data << endl;
    cout << "address: " << ((dpstruct + 2)) << ", " << "value : " << dpstruct[2]->data << endl;
    cout << "address: " << (dpstruct + 1)[1] << ", " << "value : " << (dpstruct + 1)[1]->data << endl;

    for(int i = 0 ; i < 10 ; i++){
        delete dpstruct[i];
    }
    delete [] dpstruct;

}