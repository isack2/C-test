#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#define SIZE 100

typedef struct _Node{

    char data[SIZE];
    _Node *next;

}Node;

typedef struct _Stack
{
    Node *top;

}Stack;

void push(Stack *, char *);
char *pop(Stack *);
int priority(char *);
void getinput(char *);
void postfrix(Stack *, char **, char*);

int main(void){
    using namespace std;
    Stack *stack = new Stack;
    stack->top = NULL;
    char prix[SIZE] = {" "};

    cin.getline(prix, SIZE);
    int size = 0;
    size = strlen(prix);

    char **bucket = new char*[SIZE];
    for(int i = 0 ; i < SIZE ; i++){
        bucket[i] = new char[SIZE];
    }

    char *tox = new char;
    tox = strtok(prix, " ");

    for(int i = 0 ; i < size ; i++){
        if(tox != NULL){
            strcpy(bucket[i], tox);
            tox = strtok(NULL, " ");
        }
    }
    postfrix(stack, bucket, prix);
    cout << prix << endl; 

    for(int j = 0 ; j < SIZE ; j++){
        delete [] bucket[j];
    }
    delete [] bucket;
    delete stack;
 
}

void push(Stack *stack, char *chdata){
    Node *node = new Node;

    strcpy(node->data, chdata);
    if(stack->top == NULL){
        stack->top = node;
    }
    else{
        node->next = stack->top;
        stack->top = node;
    }
}

char *pop(Stack *stack){
    Node *temp;
    char *temparr = new char;

    if(stack->top == NULL){
        std::cout << "empty" << std::endl;
    }
    else{
        temp = stack->top;
        strcpy(temparr, stack->top->data);
        stack->top = temp->next;
        delete temp;
        }
    return temparr;
}

int priority(char *arr){
    int priority; //피연산자는 그냥 출력, 스택이 비었으면 스택에 연산자 입력, 
                  //스택에 있는 연산자와 우선순위가 같거나 더 작으면 스택에 있는 연산자를 꺼내고 자신은 스택에 입력
    if(!strcmp(arr, "(")){ //여는 괄호가 나오면 스택에 입력 닫는괄호가 나오면 여는 괄호까지 출력하고 여는 괄호는 버림, 수식이 끝나면 스택에 있는 모든 연산자 출력
        priority = 3;
        }
    else if(!strcmp(arr, "+") || !strcmp(arr, "-")){
        priority = 1;
        }
    else if(!strcmp(arr, "*") || !strcmp(arr, "/")){
        priority = 2;
        }   
    else{
        priority = 0; 
        }            
    return priority;  
}

void postfrix(Stack *stack, char **str, char *rarr){
    char *pprix = new char;

    for(int i = 0 ; i < SIZE ; i++){
        if(!strcmp(str[i], "+") || !strcmp(str[i], "-") || !strcmp(str[i], "*") || !strcmp(str[i], "/")){
            while(stack->top != NULL && (priority(stack->top->data) >= priority(str[i]))){
                strcat(pprix, pop(stack));
                strcat(pprix, " ");
            }
            push(stack, str[i]);
        }
        else if(!strcmp(str[i], "(")){
            push(stack, str[i]);
        }
        else if(!strcmp(str[i], ")")){
            while(stack->top != NULL && !strcmp(stack->top->data, "(")){
                strcat(pprix, pop(stack));
                strcat(pprix, " ");
            }
            if(stack->top != NULL){
                pop(stack);
            }
        }
        else{
            strcat(pprix, str[i]);
            strcat(pprix, " ");
        }
    }
    
    if(stack->top != NULL){
        while(stack->top != NULL){
            strcat(pprix, pop(stack));
        }
    }
    
    for(int j = 0 ; j < SIZE ; j++){
        strcpy(rarr, " ");
    }
    strcpy(rarr, pprix);
}

void getinput(char *arr){
    std::cout << "Input: ";
    std::cin.getline(arr, SIZE);
}
