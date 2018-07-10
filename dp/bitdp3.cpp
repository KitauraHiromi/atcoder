#include <bits/stdc++.h>
#define MAX_N 15
#define MAX_M 15
using namespace std;
int dp[MAX_N][MAX_M][2][1<<MAX_M];
int main(void){
	for(int s=(1<<MAX_M)-1; s>=0; s--){
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<2; k++){
					dp[i][j][k][s] +=  
				}
			}
		}
	}
}