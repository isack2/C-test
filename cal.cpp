#include<iostream>
#include<cstdlib>
#include<cstring>
#define SIZE 100

//strcpy 혹은 strtok 등의 함수에 원볼배열을 직접 이용하면 원본 배열이 수정된다.

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
char *postfrix(Stack *, char **, int);
char *calcul(Stack *, char*, int);
int charsize(char *);
int wordsize(char *);
char *calcul(char **, Stack *, int);

int main(void){
    using namespace std;
    Stack *stack = new Stack;
    stack->top = NULL;
    char *o_prix = new char[SIZE];
    char *m_prix = new char[SIZE];

    cin.getline(o_prix, SIZE);
    cout << "input: " << o_prix << endl;
    strcpy(m_prix, o_prix);

    int csize = 0;
    int wsize = 0;
    
    csize = charsize(m_prix);
    wsize = wordsize(m_prix);

    char **bucket = new char*[wsize];
    for(int i = 0 ; i < wsize ; i++){
        bucket[i] = new char;
    }

    char *tox = new char;
    tox = strtok(m_prix, " ");

    for(int i = 0 ; i < wsize ; i++){
        if(tox != NULL){
            bucket[i] = tox;
            tox = strtok(NULL, " ");
        }
    }

    cout << "=====befor frix===== " << endl;
    cout << o_prix << endl;
    for(int i = 0 ; i < wsize ; i++){
        cout << "bucket[" << i << "]: " << bucket[i] << endl;
    }

    cout << "=====after frix====" << endl;
    strcpy(m_prix, postfrix(stack, bucket, wsize));
    cout << m_prix << endl;

    tox = strtok(m_prix, " ");
    for(int i = 0 ; i < wsize ; i++){
        bucket[i] = tox;
        tox = strtok(NULL, " ");
    }
    for(int i = 0 ; i < wsize ; i++){
        cout << "bucket[" << i << "]: " << bucket[i] << endl;
    }
    
    cout << "=====value====" << endl;
    cout << calcul(bucket, stack, wsize) << endl;

    for(int j = 0 ; j < wsize ; j++){
        delete [] bucket[j];
    }
    delete [] bucket;
    delete stack;
    delete [] m_prix;
    delete [] o_prix;
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
        priority = 0;
        }
    else if(!strcmp(arr, "+") || !strcmp(arr, "-")){
        priority = 1;
        }
    else if(!strcmp(arr, "*") || !strcmp(arr, "/")){
        priority = 2;
        }   
    else{
        priority = 3; 
        }            
    return priority;  
}

char *postfrix(Stack *stack, char **str, int size){
    char *pprix = new char[SIZE];

    for(int i = 0 ; i < size ; i++){
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
            while(strcmp(stack->top->data, "(")){
                strcat(pprix, pop(stack));
                strcat(pprix, " ");
            }
            pop(stack);
        }
        else{
            strcat(pprix, str[i]);
            strcat(pprix, " ");
        }
    }
    while(stack->top != NULL){
        if(!strcmp(stack->top->data, "(")){
            pop(stack);
        }
        else{
            strcat(pprix, pop(stack));
            strcat(pprix, " ");
        }
    }
    return pprix;
}

int charsize(char *arr){
    int i = 0;
    int csize = 0;

    while(arr[i] != '\0'){
        if(arr[i] == ' '){
            i++;
        }
        csize++;
        i++;
    }
    return csize;
}

int wordsize(char *arr){
    int wsize = 0;
    char *tox = new char;
    char *temparr = new char;
    char **bucket = new char*[SIZE];

    for(int i = 0 ; i < SIZE ; i++){
        bucket[i] = new char;
    }

    strcpy(temparr, arr);
    tox = strtok(temparr, " ");

    for(int i = 0 ; i < SIZE ; i++){
        if(tox != NULL){
            wsize++;
            tox = strtok(NULL, " ");
        }
    }
    delete tox;
    delete temparr;
    return wsize;
}

char *calcul(char **arr, Stack *stack, int size){
    int a = 0;
    int b = 0;
    int c = 0;
    char *temp = new char[SIZE];

    for(int i = 0 ; i < size ; i++){
        if(atoi(arr[i])){
            push(stack, arr[i]);
        }
        else if(!atoi(arr[i])){
            if(!strcmp(arr[i], "+")){
                a = atoi(pop(stack));
                b = atoi(pop(stack));
                c = b + a;
                sprintf(temp, "%d", c);
                push(stack, temp);
                a = 0;
                b = 0;
                temp = 0;
            }
            else if(!strcmp(arr[i], "-")){
                a = atoi(pop(stack));
                b = atoi(pop(stack));
                c = b - a;
                sprintf(temp, "%d", c);
                push(stack, temp);
                a = 0;
                b = 0;
                temp = 0;
            }
            else if(!strcmp(arr[i], "*")){
                a = atoi(pop(stack));
                b = atoi(pop(stack));
                c = b * a;
                sprintf(temp, "%d", c);
                push(stack, temp);
                a = 0;
                b = 0;
                temp = 0;
            }
            else if(!strcmp(arr[i], "-")){
                a = atoi(pop(stack));
                b = atoi(pop(stack));
                c = b / a;
                sprintf(temp, "%d", c);
                push(stack, temp);
                a = 0;
                b = 0;
                temp = 0;
            }
        }
    }
    return pop(stack);
}