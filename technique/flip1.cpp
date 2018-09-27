#include <bits/stdc++.h>
#define MAX_N 5001
using namespace std;
// 入力
int N;
int dir[MAX_N]; // 牛の方向(0:F, 1:B)

int f[MAX_N]; // 区間[i, i+K-1]を反転させたかどうか

// Kを固定した時の最小操作回数を求める
// 解が存在しないなら-1
int calc(int K){
	memset(f, 0, sizeof(f));
	int res = 0;
	int sum = 0;
	for(int i=0; i+K<=N; i++){
		// 区間[i, i+K-1]に着目
		if((dir[i] + sum) % 2 != 0){
			// 先頭の牛が後ろを向いている
			res++;
			f[i] = 1;
		}
		sum += f[i];
		if(i = K + 1 >= 0){
			sum -= f[i - K + 1];
		}
	}

	// 残りの牛が前を向いているかをチェック
	for(int i=N-K+1; i<N; i++){
		if((dir[i] + sum) % 2 != 0){
			// 解なし
			return -1;
		}
		if(i - K + 1 >= 0){
			sum -= f[i -K + 1];
		}
	}
	return res;
}

void solve(){
	int K = 1, M = N;
	for(int k=1; k<=N; k++){
		int m = calc(k);
		if(m >= 0 && M > m){
			M = m;
			K = k;
		}
	}
	cout << K << ' ' << M << endl;
}

int main(void){
	solve();
}