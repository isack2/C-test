#include<iostream>
#include<cstdlib>

const double *f1(const double *, int);
const double *f2(const double *, int);
const double *f3(const double *, int);

int main(void){

    using namespace std;
    double av[3] = {1112.3, 1542.6, 2227.9};

    const double *(*p1)(const double *, int);
    const double *(*p2)(const double *, int);
    const double *(*p3)(const double *, int);

    p1 = f1;
    p2 = f2;
    p3 = f3;

    cout << "함수:\n" << "주소 값\n";
    cout << f1(av, 3) << ": " << *f1(av, 3) << endl;
    cout << f2(av,3) << ": " << *f2(av, 3) << endl;
    cout << f3(av, 3) << ": " << *f3(av, 3) << endl;

    cout << "함수 포인터:\n" << "주소 값\n";
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p1(av,3) << ": " << *p1(av, 3) << endl;
    cout << (*p2)(av, 3) << ": " << *(*p2)(av, 3) << endl;
    cout << p2(av,3) << ": " << *p2(av, 3) << endl;
    cout << (*p3)(av, 3) << ": " << *(*p3)(av, 3) << endl;
    cout << p3(av,3) << ": " << *p3(av, 3) << endl;

    const double *(*pa[3])(const double *, int) = {f1, f2, f3};
    const double *(**pb)(const double *, int) = pa; //함수포인터들의 배열 pa의 원소(함수 포인터)를 가리키는 함수 포인터(이중 포인터)
    
    cout << "\n함수 포인터를 원소로 가지는 배열:\n";
    cout << "주소 값\n";

    for(int i = 0 ; i < 3 ; i++){
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
    }

    cout << "\n함수 포인터를 가리키는 포인터:\n";
    cout << "주소 값\n";

    for(int i = 0 ; i < 3 ; i++){

        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
    }

    cout << "\n포인터를 원소로 가지는 배열을 가리키는 포인터:\n";
    cout << "주소 값\n";

    const double *(*(*pc)[3])(const double *, int) = &pa; // pc는 함수포인터 3개의 배열 pa를 가르키는 함수 포인터(함수포인터 3개의 배열 자체를 가르킨다)
    const double *(*(*pd)[3])(const double *, int) = &pa;
    const double *pdb = (*pd)[1](av, 3);

    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    cout << pdb << ": " << *pdb << endl;
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;

    return 0;

}

const double *f1(const double *ar, int n){

    return ar;
}

const double *f2(const double *ar, int n){

    return ar + 1;
}

const double *f3(const double *ar, int n){

    return ar + 2;
}