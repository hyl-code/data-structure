#include <iostream>
#include "queue.cpp"
using namespace std;

const int N = 8;

int main(){
    SqQueue Q;
    InitQueue_Sq(Q, N, 10);
    for(int i = 0; i < N; i++){
        EnQueue_Sq(Q,i+1); 
    }
    int flag = 1;
    while(QueueLength_Sq(Q) > 0){
        int e;
        DeQueue_Sq(Q, e);
        if(flag == 1){
            cout << e << " ";
            flag = 2;
        }else{
            EnQueue_Sq(Q,e);
            flag = 1;
        }
    }
    return 0; 
}
