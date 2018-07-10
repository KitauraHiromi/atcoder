#include <bits/stdc++.h>
#define MAX_V 30
#define MAX_N 8
#define INF 1<<20;
using namespace std;
int dp[1<<8][MAX_V]; // dp[S][v]: 都市vにいて残りの乗車券集合がS. min(dp[S][b-1])を求めたい.
int d[MAX_V][MAX_V]; // 都市間の距離
int t[MAX_N]; // チケット
int a, b, n, m;
int main(void){
	int ret = INF;
	for(int s=(1<<8)-1; s>=0; s--){
		ret = min(ret, dp[s][b-1]);
		for(int v=0; v<MAX_V; v++){
			for(int u=0; u<MAX_V; u++){
				if(d[u][v] > 0){ // 隣接していない都市は探索しない
					for(int i=0; i<MAX_N; i++){
						if(!(s>>i&1)) dp[s][v] = min(dp[s][v], dp[s&~(1<<i)][u] + (double)d[u][v]/t[i]);
					}
				}
			}
		}
	}
}