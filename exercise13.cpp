#include<iostream>
#include"stack.cpp"
using namespace std;

const int NUM = 6;

typedef struct ArcCell{
    int adj;
    char* info;
}ArcCell,AdjMatrix[NUM][NUM];

typedef struct{
    int vexa[NUM];
    AdjMatrix arca;
}Mgraph;

void DFSreverse(int sou[NUM][NUM], int res[NUM]){
    SqStack s;
    InitStack_Sq(s);
    int i = 1;
    int n = 0;
    cout << 0;
    res[0] = 1;
    while(i < NUM){
        for(int j = 0; j < NUM; j++){
            if(res[j] == 0 && sou[n][j] == 1){
                Push_Sq(s, j);
                res[j] = 1;
            }
        }
        Pop_Sq(s, n);
        cout << n;
        i++;
        if(StackEmpty_Sq(s)){
            for(int k = 0; k < NUM; k++){
                if(res[k] == 0){
                    Push_Sq(s, k);
                    break;
                }
            }
        }
    }

}

int main(){
    int test[6][6] = {{0,1,1,0,0,0},
                      {1,0,0,0,1,0},
                      {1,0,0,0,1,0},
                      {0,0,0,0,0,1},
                      {0,1,1,0,0,0},
                      {0,0,0,1,0,0}};
    int res[6] = {0};
    DFSreverse(test, res);

}
