#include<iostream>

void select(int *);

int main(void){

    using namespace std;
    srand(time(NULL));
    int count;
    cin >> count;
    int arr[count];

    for(int i = 0 ; i < count ; i++){
        int temp = rand() % 45 + 1;
        arr[i] = temp;
    }

    for(int i = 0 ; i < count ; i ++){
        std::cout << arr[i] << endl;
    }
}
