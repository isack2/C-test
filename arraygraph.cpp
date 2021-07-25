#include<iostream>
using namespace std;

int main(void){
    int node, edge;
    cin >> node >> edge;

    int **graph = new int *[node + 1];
    for(int i = 0 ; i < edge + 1 ; i++){
        graph[i] = new int[edge + 1];
    }

    for(int i = 1 ; i < node + 1; i++){
        for(int j = 1 ; j < edge + 1; j++){
            cout << "value of edge " << i << " node to " << j << " ";
            cin >> graph[i][j];
        }
    }

    for(int i = 1 ; i < node + 1; i++){
        cout << endl;
        for(int j = 1 ; j < edge + 1; j++){
            cout << graph[i][j] << " ";
        }
    } 

    for(int i = 0 ; i < edge + 1 ; i++){
        delete graph[i];
    }

    delete [] graph;
}