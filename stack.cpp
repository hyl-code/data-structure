#include <iostream>
using namespace std;

// À≥–Ú’ª
const int STACK_INIT_SIZE = 100;
const int STACKINCREMENT = 10;

typedef int SElemType;

typedef struct{
    SElemType *elem;
    int top;
    int stacksize;
    int incrementsize;
}SqStack;

void InitStack_Sq(SqStack &S, int maxsize = STACK_INIT_SIZE, int incresize = STACKINCREMENT){
    S.elem = new SElemType[maxsize];
    S.top = -1;
    S.stacksize = maxsize;
    S.incrementsize = incresize;
}

bool GetTop_Sq(SqStack S, SElemType &e){
    if(S.top == -1)     return false;
    e = S.elem[S.top];
    return true;
}

void Push_Sq(SqStack &S, SElemType e){
    if(S.top == S.stacksize-1)      cout << "ERROR";
    S.elem[++S.top] = e;
}

bool Pop_Sq(SqStack &S, SElemType &e){
    if(S.top == -1)     return false;
    e = S.elem[S.top--];
    return true;
}

bool StackEmpty_Sq(SqStack S){
    if(S.top == -1)     return true;
    else    return false;
}

void StackTraverse_Sq(SqStack S){
    for(int i = 0; i < S.top; i++){
        cout << S.elem[i] <<" ";
    }
}

bool StackFull_Sq(SqStack S){
    if(S.top == S.stacksize-1)    return true;
    return false;
}

//¡¥’ª
typedef struct LNode{
    SElemType data;
    struct LNode *next;
    int length;
}LNode,*LinkStack;

void InitStack_L(LinkStack &S){
    S->data = 0;
    S->next = NULL;
    S->length = 0;
}

void Push_L(LinkStack &S, SElemType e){
    LNode* p = new LNode;
    p->data = e;
    p->next = S;
    S = p;
    S->length++;
}

bool Pop_L(LinkStack &S, SElemType &e){
    if(S){
        LNode* p = new LNode;
        p = S;
        S = S->next;
        e = p->data;
        delete p;
        S->length--;
        return true;
    }
    else return false;
}
