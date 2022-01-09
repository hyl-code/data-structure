#include <iostream>
#include <iomanip>
#define NUM 10
using namespace std;

typedef struct{
	int *elem;
	int length;
}SqList;

void QuickSort(SqList & L, int low, int high){
	// i指向小于枢轴的最后一个元素 , k指向大于枢轴的最后一个元素
	// j指向当前待考察的元素  
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
	}//划分小于枢轴、等于枢轴、大于枢轴 
	QuickSort(L, low, i);
	QuickSort(L, k, high);
}

int main(void){
	int a[NUM];
	SqList L;
	int i;
	cout << "请输入一个大小为10的数组：" << endl; 
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
