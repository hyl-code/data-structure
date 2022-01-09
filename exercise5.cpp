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
	//����һ����ջ S , ��ʼ��������ռ�Ϊ maxsize , Ԥ�����������Ϊ incresize 
	S.elem = new int[maxsize];		//Ϊ˳��ջ����һ���������Ϊ maxsize ������ռ� 
	S.top = -1;  					//˳��ջ�е�ǰ����Ԫ�صĸ���Ϊ 0 
	S.stacksize = maxsize;			//��˳��ջ�������� maxsize ������Ԫ��
	S.incrementsize = incresize; 	//��Ҫʱÿ�ο����� incresize ��Ԫ�صĿռ� 
} 

void incrementStacksize(SqStack &S){
	int a[];
	a = new int[S.stacksize + S.incrementsize];			// a Ϊ��ʱ���ɵĸ������� 
	for(int i = 0; i < S.stacksize; i++)				
		a[i] = S.elem[i];								//��Ųԭ�ռ�����
	delete[] S.elem;									//�ͷ�����Ԫ����ռԭ�ռ� L.elem 
	S.elem = a;											//�ƽ��ռ��׵�ַ 
	S.stacksize += S.incrementsize;						//���ݺ��˳������ռ� 
}

bool GetTop(SqStack S, int &e){
	//��ջ���� , ���� e ���� S ��ջ��Ԫ�� , ������ TURE ; ���򷵻� FALSE
	if(S.top == S.stacksize - 1)
		return false;
	e = S.elem[S.top];
	return true;
} 

void Push(SqStack &S, int e){
	if(S.top == S.stacksize - 1)
		incrementStacksize(S);			//��˳��ջ�ĵ�ǰ�ռ��ѱ�ռ��ʱ , Ӧ����˳���Ϊ S.elem
										//���·���ռ� (׷�� S.incrementsize ��Ԫ�ؿռ�)
	S.elem[++S.top] = e; 
}

bool Pop(SqStack &S, int &e){
	//��ջ���� , ��ɾ�� S ��ջ��Ԫ�� , �� e ������ֵ , ������ TRUE ;
	//���򷵻� FALSE
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
