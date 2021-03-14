#include<iostream>

int sum(int *, int *);
int *multi1(int *, int*);
int *multi2(int *, int*);
int *multi3(int *, int*);

int main(void){

    using namespace std;
    int a1 = 5;
    int a2 = 6;
    int a3 = 7;
    int *c1 = &a1;
    int *c2 = &a2;
    int *c3 = &a3;
    int *d = new int;
    int *parr[3] = {c1, c2, c3}; //int형 포인터를 3개 저장할 수 있는 배열
    int **paarr = parr; //int 형 포인터 3개 배열을 가르키는 포인터

    int (*pt)(int *, int *) = sum; //int* 형 함수 sum 을 가리키는 함수포인터 (*pt), datatype function(...) -> datatype (*function name)(...)
    int (*(*ptt))(int *, int *) = &pt; //int* 형 함수포인터 (*pt)를 가리키는 함수포인터 (*(*ptt)), (*pt)를 A라 하면 (*A)(...) 따라서 (*(*ptt))
    int (*(*(*pttt)))(int *, int *) = &ptt; //int* 형 함수포인터 (*(*ptt))를 가리키는 함수포인터 (*(*(*pttt))) (*(*ptt))를 A라 하면 (*A)(...) 따라서 (*(*(pttt)))

    cout << sum(c1, d) << endl;
    cout << pt(c1, d) << endl; //함수포인터가 (*pt) 이므로 함수이름은 pt
    cout <<  (*ptt)(c2, d) << endl; //함수포인터가 (*(*ptt)) 이므로 함수이름은 (*ptt)
    cout << (*(*pttt))(c3, d) << endl; //함수포인터가 (*(*(*pttt))) 이므로 함수이름은 (*(pttt))

    delete d;

    int *f = new int;
    int *(*pdtr[3])(int *, int *) = {multi1, multi2, multi3}; // 함수포인터 3개의 배열
    int *(**pdttr)(int *, int *) = pdtr; // 함수포인터 3개의 배열을 가리키는 함수포인터
    int *(*(*pttr)[3])(int *, int *) = &pdtr; // 함수포인터 3개이 배열을 가리키는 함수포인터를 가리키는 함수포인터
}

int sum(int *p, int *r){
    *r = *p + 100;
    return *r;
}

int *multi1(int *b, int *r){
    *r = *b = 1000;
    return r;
}

int *multi2(int *b, int *r){
    *r = *b = 1000;
    return r;
}

int *multi3(int *b, int *r){
    *r = *b = 1000;
    return r;
}