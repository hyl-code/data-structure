#include <iostream>
#include <iomanip>
using namespace std;

#define NUM 10

void mergeSort(int *a, int *b, int low, int high){
	int mid = (low + high) / 2;
	int *c;
	int i = low, j = mid + 1, k = low;
	
	if(low == high){
		b[low] = a[low];
	}else{
		c = new int[NUM];
		mergeSort(a, c, low, mid);
		mergeSort(a, c, mid+1, high);
		//c的前后部分归并入b
		while(i <= mid && j <= high){
			if(c[i] % 2 == 1 && c[j] % 2 == 0 || (c[i] + c[j]) % 2 == 0 && c[i] <= c[j] ){
				b[k++] = c[i++];
			}else{
				b[k++] = c[j++];
			}
		}
		while(i <= mid)
			b[k++] = c[i++];
		while(j <= high)
			b[k++] = c[j++];
		delete []c;
	}
} 
