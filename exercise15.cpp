#include<iostream>
using namespace std;

int binarySearch(int val, int arr[], int left, int right){
    if(left < right){
        int i = (left + right) / 2;
        if(val == arr[i])   return i+1;
        if(val < arr[i])    binarySearch(val, arr, left, i-1);
        if(val > arr[i])    binarySearch(val, arr, i+1, right);
    }
    else    return -1;
}

int binarySearch(int val, int arr[], int len){
    int low = 0, high = len-1;
    while(low < high){
        int mid = (low + high) / 2;
        if(val == arr[mid])   return mid+1;
        else if(val < arr[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int len, int i){
    int largest = i;
    int lchild = 2*i+1;
    int rchild = 2*i+2;
    if(lchild < len && arr[lchild] > arr[largest])    largest = lchild;
    if(rchild < len && arr[rchild] > arr[largest])    largest = rchild;
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, len, largest);
    }
}

void heapSort(int arr[], int len){
    for(int i = len / 2; i >= 0; i--){
        heapify(arr, len, i);
    }
    for(int i = len - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int a[10] = {1, 5, 2, 8, 9, 4, 3, 6, 7, 0};
    int test;
	heapSort(a, 10);
    cin >> test;
    cout << binarySearch(test, a, 10);
}
