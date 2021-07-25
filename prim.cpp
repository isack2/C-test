#include<iostream>
using namespace std;
#define NODE_MAX 100
#define EDGE_MAX 2000

typedef struct _Edge{
    int node;
    int edge;
}Edge;

typedef struct _Priorityque{
    Edge *heap[NODE_MAX];
    int index = 0;
}Priorityque;

typedef struct _Node{
    Edge *data = nullptr;
    _Node *next = nullptr;
}Node;

void swap(Edge *, Edge *);
void addque(Priorityque *, Edge *);
void insertnode(Node **, Edge *, int);
Edge *pop(Priorityque *);
void checkout(int **, int);

int main(void){
    int node, edge;
    cout << "input number of node: ";
    cin >> node;
    cout << "input number of edge: ";
    cin >> edge; 

    Node **bucket = new Node*[node + 1];
    for(int i = 1 ; i < node + 1 ; i++){
        bucket[i] = new Node;
        bucket[i] = nullptr;
    }
  
    for(int i = 0 ; i < edge ; i++){
        int curnode, targetnode, edge;
        cout << "input curnode, targetnode, edge: ";
        cin >> curnode >> targetnode >> edge;
        Edge *forward = new Edge;
        forward->node = targetnode;
        forward->edge = edge;
        Edge *reverse = new Edge;
        reverse->node = curnode;
        reverse->edge = edge;
        insertnode(bucket, forward, curnode);
        insertnode(bucket, reverse, targetnode);
    }
    
    /*노드 연결 테스트
    for(int i = 1 ; i < node + 1 ; i++){
        Node *xur = new Node;
        xur = bucket[i];
        while(xur != nullptr){
            cout << i << " to " << xur->data->node << " edge: " << xur->data->edge << endl;
            xur = xur->next;
        }
    }*/

    for(int i = 1 ; i < node + 1 ; i++){
        Priorityque *xque = new Priorityque;
        Node *xnode = new Node;
        xnode = bucket[i];
        while(xnode != nullptr){
            addque(xque, xnode->data);
            xnode = xnode->next;
        }
        while(xque != nullptr){
            cout << "node: " << pop(xque)->node << " edge: " << pop(xque)->edge;
        }
    }
    
    /*
    //프림 알고리즘 시작
    int res = 0;
    int nextnode = 1;
    int visit[NODE_MAX] = {0};

    for(int i = 1 ; i < node + 1 ; i++){
        Node *cur = new Node;
        Priorityque *que = new Priorityque;
        cur = bucket[nextnode];
        if(cur == nullptr){
            cout << "not a connected edge" << endl;
            (nextnode)++;
            continue;
        }
        while(cur != nullptr){
            addque(que, cur->data);
            cur = cur->next;
        }
        Edge *temp = new Edge;
        temp = pop(que);
        while(!visit[nextnode] && cur != nullptr){
            if(!visit[temp->node]){
                visit[nextnode] = 1;
                nextnode = temp->node;
                res = res  + temp->edge;
                break;
            }
            temp = pop(que);
            nextnode = temp->node;
        }
    }
    cout << "Min edge: " << res;*/
}

void swap(Edge *target, Edge *cur){
    Edge *temp;
    temp = target;
    target = cur;
    cur = target;
}

void addque(Priorityque *que, Edge *data){
    if(que->index >= NODE_MAX){
        cout << "Over Node" << endl;
    }
    else{
        que->heap[que->index] = data;
        int cur = que->index;
        int parrent = (cur - 1) / 2;
        while(parrent >= 0 && que->heap[parrent]->edge > que->heap[cur]->edge){
            swap(que->heap[cur], que->heap[parrent]);
            cur = parrent;
            parrent = (cur - 1) / 2;
        }
        (que->index)++;
        }
    }

Edge *pop(Priorityque *que){
    if(que == nullptr){
        cout << "NULL" << endl;
        return 0;
    }
    else{
        int cur = 0;
        int target = (que->index)--;
        int left = 1;
        int right = 2;
        Priorityque *temp = new Priorityque;
        temp->index = cur;
        temp->heap[cur] = que->heap[cur];
        que->heap[cur] = que->heap[target];
        que->index = target;
        delete que->heap[target];
        target--;
        while(left <= target){
            if(que->heap[cur]->edge > que->heap[left]->edge && que->heap[left]->edge < que->heap[right]->edge){
                swap(que->heap[cur], que->heap[left]);
                cur = left;
                left = cur * 2 + 1;
                right = cur * 2 + 2; 
            }
            else if(que->heap[cur]->edge > que->heap[right]->edge && que->heap[left]->edge > que->heap[right]->edge && right <= target){
                swap(que->heap[cur], que->heap[right]);
                cur = right;
                left = cur * 2 + 1;
                right = cur * 2 + 2;
            }
            else
                break;
        }
        return temp->heap[0];
    }
}

void insertnode(Node **bucket, Edge *heap, int index){
    if(index >= NODE_MAX){
        cout << "Node Over" << endl;
    }
    else if(bucket[index] == nullptr){
        bucket[index] = new Node;
        bucket[index]->data = heap;
    }
    else{
        Node *node = new Node;
        node->data = heap;
        node->next = bucket[index];
        bucket[index] = node;
    }
}