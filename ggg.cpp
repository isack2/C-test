#include<iostream>

int main(void){

    using namespace std;

    double a = 5.0;
    double b = 3.4;
    double c = 2.5;
    double *pa = &a;
    double *pb = &b;
    double *pc = &c;

    //배열
    double arr[3] = {a, b, c};
    double (*at)[3] = &arr;
    double (**aat)[3] = &at;
    double (***aaat)[3] = &aat; 

    //포인터 배열
    double *par[3] = {pa, pb, pc};
    double **xar = par;
    double *(*ppar)[3] = &par;
    double *(**pxar)[3] = &ppar;
    double *(*(*pppar))[3] = &ppar; 

    cout << "a adress: " << &a << ",  " << "a value: " << a << endl;
    cout << "b adress: " << &b << ",  " << "b value: " << b << endl;
    cout << "c adress: " << &c << ",  " << "c value: " << c << endl;
    cout << endl;

    cout << "(xar + i): " << xar << " " << xar + 1 << " " << xar + 2 << endl;//배열 par의 주소
    cout << "(xar[i]): " << xar[0] << " " << xar[1] << " " << xar[2] << endl; //pa, pb, pc의 주소, 배열 xar[i]는 *(xar + i) 와 같으므로 pa, pb, pc 의 주소가 호출 된다. 배열명[] 호출은 해당 포인터의 참조와 같다.
    cout << "(&par[i]): " << &par[0] << " " << &par[1] << " " << &par[2] << endl;//배열 par의 주소
    cout << "(par[i]): " << par[0] << " " << par[1] << " " << par[2] << endl;//배열 par의 주소

    cout << "(&arr[i]): " << &arr[0] << " " << &arr[1] << " " << &arr[2] << endl; //배열의 주소(8byte)
    cout << "(arr[i]): " << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    cout << "(at): " << at[0] << " " << at[1] << " " << at[2] << "  " << *at[0] << "  " << *at[1] << "  " << *at[2] << endl; //배열을 가르키는 포인터의 주소(24byte)
    cout << "(aat + i): " << aat << " " << aat + 1 << " " << aat + 2 << endl;
    cout << "(aat[i]): " << aat[0] << " " << aat[1] << " " << aat[2] << endl; //배열을 가르키는 포인터를 가르키는 포인터의 주소()
    cout << "(*aat[i]): " << *aat[0] << " " << *aat[1] << " " << *aat[2] << endl;
    cout << "(**aat[i]): " << **aat[0] << " " << **aat[1] << " " << **aat[2] << endl;
    cout << aaat[0] << " " << aaat[1] << " " << aaat[2] << "  " << *aaat[0] << "  " << *aaat[1] << "  " << *aaat[2] << endl; // 배열을 가르키는 포인터를 가르키는 포인터를 가르키는 포인터의 주소

    cout << endl;
    cout << "pointer " << endl << endl;
    cout  << pa << " " << pb << " " << pc << " " << *pa << " " << *pb << " " << *pc << endl; 
    for(int i = 0 ; i < 3 ; i++){
        cout << "*par[3]: " << par[i] << " " << *par[i] << endl;
    }
    cout << endl;
    for(int i = 0 ; i < 3 ; i++){
        cout << "*(*ppar)[3]: " << ppar[i] << " " << *ppar[i] << endl;
    }
    cout << endl;
    for(int i = 0 ; i < 3 ; i++){
        cout << "*(*(*pppar))[3]: " << pppar[i] << " " << *pppar[i] << endl;
    }
    cout << endl;
    for(int i = 0 ; i < 3 ; i++){
        cout << "*(**pxar)[3]: " << pxar[i] << " " << *pxar[i] << endl;
    }

}