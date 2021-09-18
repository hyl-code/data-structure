#include <process.h>
#include <iostream>
using   namespace   std; 

#define NUM 5

const LIST_INIT_SIZE = 100;
const LISTINCREMENT = 10;

typedef struct{
	int *elem;
	int length;
	int listsize;
	int incrementsize;
}SqList;

void increment(SqList &L){
	int i;
	int *a = new int[L.listsize + L.incrementsize];
	for(i = 0; i < L.length; i++)
		a[i] = L.elem[i];
	delete[] L.elem;
	L.elem = a;
	L.listsize += L.incrementsize;
}//扩容

void ErrorMessage(char *s){
	cout<<s<<endl;
	exit(1);
}//返回错误信息

void InitList_Sq(SqList &L){
	L.elem = new int[NUM];

	L.length = 0;
	L.listsize = NUM;
	L.incrementsize = 0;
}//初始化

void DestroyList_Sq(SqList &L){
	delete[] L.elem;
	L.listsize = 0;
	L.length = 0;
}//销毁

int LocateElem_Sq(SqList L, int e){
	int i = 1;
	int *p;
	p = L.elem;
	while(i <= L.length && *p++ != e)
		++i;
	if(i <= L.length)
		return i;
	else
		return 0;
}//定位

bool search(SqList L, int e){
	int *p;
	p = L.elem;
	int i = 1;
	while(i <= L.length && *p++ != e){
		++i;
	}
	if(*p == e)
		return true;
	else
		return false;
}//查询


void ListInsert_Sq(SqList &L, int i, int e){
	if(i < 1 || i > L.listsize + 1)
		ErrorMessage("i值不合法");
	if(L.length >= L.listsize)
		increment(L);
	int *q, *p;
	q = &(L.elem[i-1]);
	for(p = &(L.elem[L.length - 1]); p >= q; --q)
		*(p+1) = *p;
	*q = e;
	++L.length;
}//插入

void ListDelete_Sq(SqList &L, int i, int &e){
	if((i < 1) || (i > L.length))
		ErrorMessage("i值不合法");
	int *p, *q;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	for(++p; p <= q; ++p)
		*(p-1) = *p;
	--L.length;
}//删除

int main(void){
	int a[NUM] = {1, 2, 5, 6, 9};
	int b[NUM] = {2, 5, 8, 9, 10};
	SqList La, Lb, Lc;
	InitList_Sq(La);
	InitList_Sq(Lb);
	InitList_Sq(Lc);
	int i;
	int e;

	for(i = 0; i < NUM; i++){
		ListInsert_Sq(La, La.length+1, a[i]);
		ListInsert_Sq(Lb, Lb.length+1, b[i]);
	}

	for(i = 0; i < 5; i++){
		if(!search(Lb, La.elem[i])){
			ListDelete_Sq(La, i + 1, e);
			*Lc.elem = e;
			Lc.elem++;
		}
	}

	printf("A∩B = ");
	for(i = 0;i < La.length; i++){
		printf("%4d", La.elem[i]);
	}

	printf("A-B = ");
	for(i = 0;i < Lc.length; i++){
		printf("%4d", Lc.elem[i]);
	}

	return 0;
}
