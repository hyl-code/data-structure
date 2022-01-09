#include <iostream>
using namespace std;
#define NUM 5
#define INF 9999

int min(int dist[NUM], int flag[NUM]){
	int i, j = 0;
	int minval = INF;
	for(i = 0; i < NUM; i++){
		if(!flag[i] && dist[i] < minval){
			minval = dist[i];
			j = i;
		}
	}
	if(minval < INF){
		return j;
	}else{
		return -1;
	}
}

void Dijkstra(int edge[NUM][NUM], int s){
    int i, j, k;
    int dist[NUM] = {0};
    int path[NUM];
    int flag[NUM] = {0};
    flag[s] = 1;
    for(i = 0; i < NUM; i++){
        dist[i] = edge[s][i];
        path[i] = s;
    }
    for(i = 0; i < NUM-1; i++){
        k = min(dist, flag);
        if(k == -1) break;
        flag[k] = 1;
        for(j = 0; j < NUM; j++){
            if(!flag[j] && edge[k][j] < INF && dist[k] + edge[k][j] < dist[j]){
                dist[j] = dist[k] + edge[k][j];
                path[j] = k;
            }
        }
    }
    for(i = 0; i < NUM; i++){
        if(i != s && dist[i] < INF){
            k = i;
            cout << dist[k] << ":";
            while(k != s){
                cout << k << "-";
                k = path[k];
            }
            cout << s << endl;
        }
    }
}

int main(){
    int test[5][5] = {0,10,INF,30,100,
                    INF,0,50,INF,INF,
                    INF,INF,0,INF,10,
                    INF,INF,20,0,60,
                    INF,INF,INF,INF,0};
    Dijkstra(test, 0);                
}
