#include<iostream>
using namespace std;
const int MAXSIZE = 12;

typedef struct {
    int row, col;		//行列号 
    int e;				//元素值 
}Triple;

typedef struct {
    Triple data[MAXSIZE+1];		//三元组表，以行为主序，下标从0开始 
    int mu, nu, tu;				//矩阵总行数、总列数、非零元素总数 
}TSMatrix;

void createSMat(int *a, int Row, int Col, TSMatrix &Ts){
	int i, j, k = 0;
	Ts.mu = Row;
	Ts.nu = Col;
	for(i = 0; i < Row; i++){
		for(j = 0; j < Col; j++){
			if(*(a + Col * i + j) != 0){
				Ts.data[k].row = i;
				Ts.data[k].col = j;
				Ts.data[k++].e = *(a + Col * i + j);
			} 
		}
	}
	Ts.tu = k;
}

bool add(TSMatrix T1, TSMatrix T2, TSMatrix &T3){
	int i = 0, j = 0, k = 0;
	if(T1.mu != T2.mu || T1.nu != T2.nu){
		return -1;
	}
	T3.mu = T1.mu;
	T3.nu = T1.nu;
    while(i < T1.tu && j < T2.tu){
        if(T1.data[i].row == T2.data[j].row && T1.data[i].col == T2.data[j].col){//同位置元素直接相加
            T3.data[k] = T1.data[i++];
            T3.data[k++].e += T2.data[j++].e;
        }else if(T1.data[i].row < T2.data[j].row || (T1.data[i].row == T2.data[j].row && T1.data[i].col < T2.data[j].col)){//行不等 或 行等列不等 
            T3.data[k++] = T1.data[i++];
        }else{
            T3.data[k++] = T2.data[j++];
        }
    }
    while(i < T1.tu){
    	T3.data[k++] = T1.data[i++];
	}
	while(j < T2.tu){
		T3.data[k++] = T2.data[j++];
	}
	T3.tu = k;
	return 1;
}

int main(){
    int x1[3][4] = {0,0,1,0,2,0,0,1,0,1,0,0};
    int x2[3][4] = {1,0,2,0,1,0,1,0,0,0,0,1};
    TSMatrix T1, T2, T3;
    createSMat(*x1, 3, 4, T1);
    createSMat(*x2, 3, 4, T2);
    add(T1, T2, T3);
    for(int i = 0; i < T3.tu; i++){
        cout << T3.data[i].e << " ";
    }
}
