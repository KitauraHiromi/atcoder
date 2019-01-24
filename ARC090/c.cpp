// A[0][0:j+1] + A[1][j:N]を最大化するようなj
// セグ木で和を高速に計算
/*
 * Contents   : ARC 090 C AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180731
 * Since      : 20180731
 */
#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
int N, A[2][MAX_N], bit[2][MAX_N + 1];
int sum(int i, int j){
	int s = 0;
	while(i > 0){
		s += bit[j][i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x, int j){
	while(i <= N){
		bit[j][i] += x;
		i += i & -i;
	}
}

int main(void){
	cin >> N;
	for(int i=0; i<2; i++){
		for(int j=0; j<N; j++){
			cin >> A[i][j];
			add(j+1, A[i][j], i);
		}
	}
	int ret = 0;
	for(int i=0; i<N; i++){
		ret = max(ret, sum(i+1, 0) + sum(N, 1) - sum(i, 1));
	}
	cout << ret << endl;
	return 0;
}