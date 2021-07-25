#include<iostream>
using namespace std;

typedef struct _Node{
    int edge;
    int node;
    _Node *next = nullptr; 
}Node;

void insult(Node *, int, int);
void showall(Node *);

int main(void){
    int node, edge;
    int start, end, distance;
    cin >> node >> edge;

    Node **graph = new Node *[node + 1];
    for(int i = 1 ; i < edge + 1 ; i++){
        graph[i] = new Node;
    }

    for(int i = 0 ; i < node ; i++){
        cin >> start >> end >> distance;
        insult(graph[start], end, distance);
    }

    for(int i = 1 ; i < node + 1; i++){
        cout << "graph[" << i << "] : "; 
        showall(graph[i]);
        cout << endl;
    }

    for(int i = 1 ; i < edge + 1 ; i++){
        delete graph[i];
    }
    delete [] graph;

}

void insult(Node *root, int nodedata, int edgedata){
    Node *node = new Node;
    node->node = nodedata;
    node->edge = edgedata;
    if(root->next == nullptr){
        root->next = node;
    }
    else{
        node->next = root->next;
        root->next = node;
    }
}

void showall(Node *root){
    Node *cur = new Node;
    cur = root->next;
    while(cur != nullptr){
        cout << "node " << cur->node << " distance: " << "(" << cur->edge << ")" << "  ";
        cur = cur->next;
    }
}