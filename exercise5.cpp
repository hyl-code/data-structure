#include <iostream>
using namespace std;

const STACK_INIT_SIZE = 100;
const STACKINCREMENT = 10;

int &e;

typedef struct{
	int *elem;
	int top;
	int stacksize;
	int incrementsize;
}SqStack;

void InitStack_Sq(SqStack &S, int maxsize = STACK_INIT_SIZE, int incresize = STACKINCREMENT){
	//构造一个空栈 S , 初始分配的最大空间为 maxsize , 预设的扩容增量为 incresize 
	S.elem = new int[maxsize];		//为顺序栈分配一个最大容量为 maxsize 的数组空间 
	S.top = -1;  					//顺序栈中当前所含元素的个数为 0 
	S.stacksize = maxsize;			//该顺序栈可以容纳 maxsize 个数据元素
	S.incrementsize = incresize; 	//需要时每次可扩容 incresize 个元素的空间 
} 

void incrementStacksize(SqStack &S){
	int a[];
	a = new int[S.stacksize + S.incrementsize];			// a 为临时过渡的辅助数组 
	for(int i = 0; i < S.stacksize; i++)				
		a[i] = S.elem[i];								//腾挪原空间数据
	delete[] S.elem;									//释放数据元素所占原空间 L.elem 
	S.elem = a;											//移交空间首地址 
	S.stacksize += S.incrementsize;						//扩容后的顺序表最大空间 
}

bool GetTop(SqStack S, int &e){
	//若栈不空 , 则用 e 返回 S 的栈顶元素 , 并返回 TURE ; 否则返回 FALSE
	if(S.top == S.stacksize - 1)
		return false;
	e = S.elem[S.top];
	return true;
} 

void Push(SqStack &S, int e){
	if(S.top == S.stacksize - 1)
		incrementStacksize(S);			//若顺序栈的当前空间已被占满时 , 应类似顺序表为 S.elem
										//重新分配空间 (追加 S.incrementsize 个元素空间)
	S.elem[++S.top] = e; 
}

bool Pop(SqStack &S, int &e){
	//若栈不空 , 则删除 S 的栈顶元素 , 用 e 返回其值 , 并返回 TRUE ;
	//否则返回 FALSE
	if(S.top == -1)
		return false;
	e = S.elem[S.top--];
	return true; 
}

bool palindrome(void){
	SqStack S1;
	InitStack_Sq(S1, 6, 0);
	int elem[S1.stacksize] = {1, 2, 3, 3, 2, 1};
	int mid = S1.stacksize / 2;
	int num[mid] = new int[mid];
	int i;
	
	if(!GetTop(S1, e)){
		for(int i = 0; i < S1.stacksize; i++){
			Push(S1, elem[i]);	
		}
	}
	
	for(i = 0; i < mid; i++){
		if(Pop(S, e);
			num[i] = e;
	}

	do{
		Pop(S, e);
	}while(num[i++] == e && !GetTop(S, e));
	
	return i == mid - 1;
} 
