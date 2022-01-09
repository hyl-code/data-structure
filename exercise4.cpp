#include <iostream>
#include <iomanip>
#define NUM 10
using namespace std;

typedef struct{
	int *elem;
	int length;
}SqList;

void QuickSort(SqList & L, int low, int high){
	// iָ��С����������һ��Ԫ�� , kָ�������������һ��Ԫ��
	// jָ��ǰ�������Ԫ��  
	int i = low - 1;
	int j = low;
	int k = high + 1;
	int piv, temp;
	
	if(low >= high)
		return;
	piv = L.elem[low];
	while(j < k){
		if(L.elem[j] < piv){
			i++;
			temp = L.elem[j];
			L.elem[j] = L.elem[i];
			L.elem[i] = temp;
			j++;
		}else if(L.elem[j] > piv){
			k--;
			temp = L.elem[j];
			L.elem[j] = L.elem[k];
			L.elem[k] = temp; 
		}else
			j++;
	}//����С�����ᡢ�������ᡢ�������� 
	QuickSort(L, low, i);
	QuickSort(L, k, high);
}

int main(void){
	int a[NUM];
	SqList L;
	int i;
	cout << "������һ����СΪ10�����飺" << endl; 
	for(i = 0; i < NUM; i++){
		cin >> a[i];
	} 
	L.elem = a;
	L.length = NUM;
	QuickSort(L, 0, L.length - 1);
	for(i = 0; i < L.length; i++){
		cout <<setw(2)<<L.elem[i];
	}
	
}
