#include <iostream>
using namespace std;

//循环队列
typedef int QElemType;
typedef struct{
    QElemType *elem;
    int front;
    int rear;
    int queuesize;
    int incrementsize;
}SqQueue;

void InitQueue_Sq(SqQueue &Q, int maxsize, int increzise = 10){
    Q.elem = new QElemType[maxsize + 1];
    Q.queuesize = maxsize + 1;
    Q.incrementsize = increzise;
    Q.front = Q.rear = 0;
}

int QueueLength_Sq(SqQueue Q){
    return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

void incrementQueuesize(SqQueue &Q){
    QElemType *a = new QElemType[Q.queuesize + Q.incrementsize];
    for(int k = 0; k < Q.queuesize - 1; k++){
        a[k] = Q.elem[(Q.front + k) % Q.queuesize];
    }
    delete[] Q.elem;
    Q.elem = a;
    Q.front = 0;
    Q.rear = Q.queuesize - 1;
    Q.queuesize += Q.incrementsize;
}

void EnQueue_Sq(SqQueue &Q, QElemType e){
    if((Q.rear + 1) % Q.queuesize == Q.front){
        incrementQueuesize(Q);
    }
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.queuesize;
}

bool DeQueue_Sq(SqQueue &Q, QElemType &e){
    if(Q.front == Q.rear)   return false;
    e = Q.elem[Q.front];
    Q.front = (Q.front + 1) % Q.queuesize;  return true;
}

void GetHead_Sq(SqQueue Q, QElemType &e){
    e =Q.elem[Q.front];
}

//链队列
typedef struct LNode
{
    QElemType data;
    struct LNode *next;
}LNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void InitQueue_L(LinkQueue &Q){
    Q.front = Q.rear = new LNode;
    Q.front->next = NULL;
}

void DestroyQueue_L(LinkQueue &Q){
    while(Q.front){
        Q.rear = Q.front->next;
        delete Q.front;
        Q.front = Q.rear;
    }
}

void EnQueue_L(LinkQueue &Q, QElemType e){
    LNode* p = new LNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

bool DeQueue_L(LinkQueue &Q, QElemType &e){
    if(Q.front == Q.rear) return false;
    LNode* p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.rear == p){
        Q.rear = Q.front;
    }
    delete p;
    return true;
}
