#include <iostream>
#include <math.h>
#include "stack.cpp"
using namespace std;
int count = 0;

int canPlace(SqStack s, int e){
    int j;
    for(j = 0; j <= s.top; j++){
        if(s.elem[j] == e || abs(s.elem[j] - e) == abs(j - s.top - 1)){
            return 0;
        }
    }
    return 1;
}

void eightQueen(){
    SqStack s;
    InitStack_Sq(s,8,10);
    int i = 0;
    do{
        while(i < 8 && !StackFull_Sq(s)){
            if(canPlace(s,i)){
                Push_Sq(s,i);
                i = 0;
            }else{
                i++;
            }   
        }
        if(StackFull_Sq(s)){
            	count++;
                cout << "--------µÚ" << count << "ÖÖ½â---------" << endl;
                StackTraverse_Sq(s);
                cout << endl;
        }
        Pop_Sq(s,i);
        i++;
    }while(!StackEmpty_Sq(s) || i < 8);
}

int main(){
    eightQueen();
}
