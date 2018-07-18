#include <bits/stdc++.h>
#define MAX_M 10
using namespace std;
int dp[1<<MAX_M][MAX_M+1];
int n, m, Y, Z;
int main(void){
	cin >> n >> m >> Y >> Z;
	for(int i=0; i<n; i++){
		int c, p;
		cin >> c >> p;
		for(int j=(1<<MAX_M)-1; j>=0; j--){
			for(int k=0; k<=m; k++){
				// 次の色cが一番上の色kと同じ場合
				if(c == k) dp[j][k] = max(dp[j][k], dp[j][k]+p+Y);
				// 次の色cが一番上の色kと異なり、全色ボーナスありの場合
				else if(j|(1<<c) == (1<<MAX_M)-1) dp[j|1<<c][c] = max(dp[j|1<<c][c], dp[j][k]+p+Z);
				// 次の色cが一番上の色kと異なり、全色ボーナスなしの場合
				else dp[j|1<<c][c] = max(dp[j|1<<c][c], dp[j][k]+p);
			}
		}
	}
}