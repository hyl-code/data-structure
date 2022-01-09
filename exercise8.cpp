#include<iostream>
#include "queue.cpp"
using namespace std;

void originSort(){
    int n;
    int *ans = new int[n];
    cin >> n;
    SqQueue Q;
    InitQueue_Sq(Q, n+1);
    for(int i = n; i > 0; i--){
        int e;
        EnQueue_Sq(Q, i);
        DeQueue_Sq(Q, e);
        EnQueue_Sq(Q, e);
    }
    
    for(int i = n-1; i >= 0; i--){
        int e;
        DeQueue_Sq(Q, e);
        ans[i] = e;
    }
    
    for(int i = 0; i < n; i++){
    	cout << ans[i] << " ";
	}
}

void originSort2(){
    SqQueue q;
    int n, e;
    cin >> n;
    int *ans = new int[n];
    InitQueue_Sq(q, n+1);
    for(int i = 0; i < n; i++){
        EnQueue_Sq(q, i);  //这时入队的数字表示下标
    }

    for(int i = 1; i <= n; i++){
        //按规则出队，按出队的顺序判断是第几号元素
        DeQueue_Sq(q, e);
        EnQueue_Sq(q, e);
        DeQueue_Sq(q, e);
        ans[e] = i; 
    }

}


int main(){
    originSort();
}
