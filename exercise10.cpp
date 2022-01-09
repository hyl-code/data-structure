#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void createNode(BiTree &T, int i,int n){
    if(2*i+1 <= n){
        BiTree left = new BiTNode;
        BiTree right = new BiTNode;
        T->lchild = left;
        T->rchild = right;
        left->data = 2*i;
        right->data = 2*i+1;
        createNode(left, 2*i, n);
        createNode(right, 2*i+1, n);
    }else if(2*i <= n){
        BiTree left = new BiTNode;
        T->lchild = left;
        left->data = 2*i;
        T->rchild = NULL;
		left->lchild = NULL;
		left->rchild = NULL;
	}else{
        T->lchild = NULL;
        T->rchild = NULL;
    }
}

//循环队列（非递归建立完全二叉树） 
typedef struct
{
	BiTree *elem;
	int front;
	int rear;
	int maxsize;
}sqQueue;

void initqueue(sqQueue &sq,int size = 100)
{
	sq.elem = new BiTree[size];
	sq.front = sq.rear = 0;
	sq.maxsize = size;
}

void enqueue(sqQueue &sq,BiTree e)
{
	if((sq.rear+1)%sq.maxsize == sq.front) return;
	sq.elem[sq.rear] = e;
	sq.rear = (sq.rear+1)%sq.maxsize;
}

void dequeue(sqQueue &sq,BiTree &e)
{
	e = sq.elem[sq.front];
	sq.front = (sq.front+1)%sq.maxsize;
}

bool emptyqueue(sqQueue sq)
{
	if((sq.rear)%sq.maxsize == sq.front) return 1;
	return 0;
}

BiTree createsq(int n,int index,int a[])//非递归创建 
{
	sqQueue sq;
	BiTree e = new BiTNode;
	int i;
	initqueue(sq);
	BiTree root = new BiTNode;
	root->data = a[index];
	root->lchild = root->rchild = NULL;
	enqueue(sq,root);
	while(!emptyqueue(sq))
	{
		dequeue(sq,e);//出队 
		i = e->data;
		if(2*i <= n)
		{
			BiTree p = new BiTNode;
			p->data = a[2 * i];
			p->lchild = p->rchild = NULL;
			e->lchild = p;
			enqueue(sq,p);
		}
		if(2*i+1 <= n)
		{
			BiTree q = new BiTNode;
			q->data = a[2 * i + 1];
			q->lchild = q->rchild = NULL;
			e->rchild = q;
			enqueue(sq,q);
		}	
	}
	return root;
}

void Preorder(BiTree T){
    if(T){
        cout << T->data << " ";
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}

int main(){
    BiTree T = new BiTNode;
    T->data = 1;
    T->lchild = NULL;
    T->rchild = NULL;
    int n;
    cin >> n;
    createNode(T, 1, n);
    Preorder(T); 
}
