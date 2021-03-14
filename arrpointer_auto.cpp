#include<iostream>

const double *arrp1(const double *, int);
const double *arrp2(const double *, int);
const double *arrp3(const double *, int);


int main(void){

    using namespace std;

    double arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    double (*ptor)[4] = arr;

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cout << "address: " << &arr[i][j] << ",  "  << "value: " << arr[i][j] << endl;
        }
    }

    cout << endl << endl;
    
    for(int i = 0 ; i < 3 ; i ++){

        cout << "address: " << ptor[i] << ",  " << "value: " << *ptor[i] << endl;
    }

    cout << endl << endl;
    
    cout << arr << endl; //2차원 배열 즉 2중 포인터에서 배열의 이름은 1차원 배열 즉 포인터의 주소를(&arr[0]) 가르킨다.ㅠ
    cout << "arr address: " << &arr[0] << ",  " << "arr value: " << arr[0] << endl; //2차원 배열에서 arr[0] 즉 포인터는 &arr[0][0] 의 주소를 가르킨다.
    cout << "arr address: " << &arr[1] << ",  " << "arr value: " << arr[1] << endl; //2차원 배열에서 arr[1] 즉 포인터는 &arr[1][0] 의 주소를 가르킨다.
    cout << "arr address: " << &arr[2] << ",  " << "arr value: " << arr[2] << endl; //2차원 배열에서 arr[2] 즉 포인터 &arr[2][0] 의 주소를 가르킨다.
    cout << "arr address: " << &arr[0][0] << ",  " << "arr value: " << arr[0][0] << endl;
    cout << "arr address: " << &arr[1][0] << ",  " << "arr value: " << arr[1][0] << endl;
    cout << "arr address: " << &arr[2][0] << ",  " << "arr value: " << arr[2][0] << endl;
    cout << "ptor address: " << ptor[0] << ",  " << "ptor value: " << *ptor[0] << endl; //ptor이 4개 짜리 배열을 가리키는 포인터이므로 ptor[0] 은 &ptor[0][0]을 가리킨다.
    cout << "ptor address: " << ptor[1] << ",  " << "ptor value: " << *ptor[1] << endl; //ptor이 4개 짜리 배열을 가리키는 포인터이므로 ptor[1] 은 &ptor[1][0]을 가리킨다.
    cout << "ptor address: " << ptor[2] << ",  " << "ptor value: " << *ptor[2] << endl; //ptor이 4개 짜리 배열을 가리키는 포인터이므로 ptor[2] 은 &ptor[2][0]을 가리킨다.
    cout << endl;

    const double * pd1 = arr[0];
    const double * pd2 = arr[1]; 
    const double * pd3 = arr[2];

    cout << "pd1: " << pd1 << "pd1 value: " << *pd1 << endl;
    cout << "pd1: " << pd2 << "pd1 value: " << *pd2 << endl;
    cout << "pd1: " << pd3 << "pd1 value: " << *pd3 << endl;

    cout << endl << endl;

    const double *(*ptr[3])(const double *, int) = {arrp1, arrp2, arrp3};
    const double *(**ptdr)(const double *, int) = ptr;

    for(int i = 0 ; i < 3 ; i++){

        cout << ptr[i] << 
    }
    
    auto pa = &ptr;


    cout << pa[0] << " " << pa[1] << " " << pa[2] << endl;
    cout << endl;
    cout << *pa[0] << " " << *pa[1] << " " << *pa[2] << endl;
    cout << endl << endl;
}

const double *arrp1(const double *arr, int n){
    const double *temp = arr;
    const double tempv = *arr;
    return temp;
}

const double *arrp2(const double *arr, int n){
    const double *temp = arr;
    const double tempv = *arr;
    return temp;
}

const double *arrp3(const double *arr, int n){
    const double *temp = arr;
    const double tempv = *arr;
    return temp;
}