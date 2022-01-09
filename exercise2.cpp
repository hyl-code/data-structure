#include <iomanip>
#include <iostream>
using namespace std;
#define NUM 26

typedef struct Node{
	char data;
	Node *next;
}LNode, *LinkList;

void createList(LinkList &L){
	LNode *head = NULL;//��һ��Ԫ�ؽ��
	int i;
	LNode *p = new LNode;
	p->data = 'A';
	L = head = p;

	for(i = 1; i < NUM; i++){
		p = new LNode;
		p->data = 'A' + i;
		L->next = p;
		L = p;
	}
	L->next = head;//ͷβ�ν�
}

void printList(LinkList L, int pos){
	int i;
	LNode *p = L->next;
	pos = (pos % NUM + NUM) % NUM;
		
	for(i = 0; i < pos; i++)
		p = p->next;
	
	for(i = 0; i < NUM; i++){
		cout<< setw(2) << p->data;
		p = p->next;	
	}
	cout<<endl;
}

int main(){
	LinkList L;
	int pos;
	
	createList(L);
	printf("������һ�������ı���ĸ���������");
	cin>> pos;
	printList(L, pos);

	return 0;
}
