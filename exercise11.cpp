#include<iostream>
using namespace std;

typedef struct BiTreeNode{
    char data;
    struct BiTreeNode *left, *right;
}BiTNode, *BiTree;

// À≥–Ú’ª
const int STACK_INIT_SIZE = 100;
const int STACKINCREMENT = 10;

typedef BiTree SElemType;

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

bool StackFull_Sq(SqStack S){
    if(S.top == S.stacksize-1)    return true;
    return false;
}

void createBiTree(BiTree &T, char* str){
    SqStack S;
    InitStack_Sq(S);
    int popflag = 0;
    if(*str == '#') return;
    T->data = str[0];
    BiTNode *pre, *p;
    T->left = NULL;
    T->right = NULL;
    Push_Sq(S, T);
    pre = T;
    for(int i = 1; str[i] != '\0'; i++){
        if(str[i] != '#' && str[i] != '\0'){
            p = new BiTNode;
            p->data = str[i];
            p->left = p->right = NULL;
            if(popflag == 1){
                pre->right = p;
                popflag = 0;
            }else{
                pre->left = p;
            }
            Push_Sq(S, p);
            pre = p;
        }
        else if(str[i] == '#' && !StackEmpty_Sq(S)){
            Pop_Sq(S, pre);
            popflag = 1;
        }
    }
}

void Preorder(BiTree T){
    if(T){
        cout << T->data << " ";
        Preorder(T->left);
        Preorder(T->right);
    }
}

int main(){
    char str[] = "ABC##DE#G##F###";
    BiTree T = new BiTNode;
    createBiTree(T, str);
    Preorder(T);
}
