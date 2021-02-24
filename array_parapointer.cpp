#include<iostream>
#include<cstdlib>
#include<string>

typedef struct Node{

    int num;
    std::string str;
    struct Node *next;
    struct Node *prev;

}nodes;

nodes *base;
nodes *top;


void add(void);
void addnum(int);
void addstr(std::string);
void shownode(void);
void allfree(void);

int main(void){

    using namespace std;

    base = new nodes;
    top = new nodes;
    base->num = (int)NULL;
    top->num = (int)NULL;
    base->str = '\0';
    top->str = '\0';
    base->next = top;
    base->prev = NULL;
    top->prev = base;
    top->next = NULL;

    add();
    add();
    add();
    add();
    add();
    add();
    add();
    shownode();
    allfree();

}

void addnum(int numdata){

    nodes *newnode = new nodes;
    nodes *indicate;
    nodes *p_indicate;

    newnode->num = numdata;
    newnode->str = '\0';
    indicate = base->next;

    while(indicate != top){
        indicate = indicate->next;
    }

    p_indicate = indicate->prev;
    p_indicate->next = newnode;
    newnode->prev = p_indicate;
    newnode->next = indicate;
    indicate->prev = newnode;
}

void addstr(std::string str){

    nodes *newnode = new nodes;
    nodes *indicate;
    nodes *p_indicate;

    newnode->num = (int)NULL;
    newnode->str = str;
    indicate = base->next;

    while(indicate != top){
        indicate = indicate->next;
    }

    p_indicate = indicate->prev;
    p_indicate->next = newnode;
    newnode->prev = p_indicate;
    newnode->next = indicate;
    indicate->prev = newnode;
}

void add(void){

    int n_temp;
    std::string s_temp; 

    std::cout << "input : ";
    std::cin >> n_temp;
    if(!(n_temp)){
        std::cin.clear();
        std::cin >> s_temp;
        addstr(s_temp);
        std::cin.clear();
    }
    else{
        addnum(n_temp);
        std::cin.clear();
    }
}




void shownode(void){
    
    nodes *show;
    show = base->next;

    while(show != top){
        if(show->num != (int)NULL){
            std::cout << show->num << std::endl;
            show = show->next;
        }
        else{
            std::cout << show->str << std::endl;
            show = show->next;
        }
    }
}

void allfree(void){
    
    nodes *current;
    nodes *delnode;
    current = base->next;

    while(current != top){
        delnode = current;
        current = current->next;
        delete delnode;
    }
}