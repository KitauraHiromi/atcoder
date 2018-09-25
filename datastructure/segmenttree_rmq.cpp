#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define MAX_N 10000
#define INF 1<<17	
int n, a, b, dat[2 * MAX_N - 1];

void init(){
	for(int i = n-1; i<2*n-1; i++) cin >> dat[i];
	for(int i = n-2; i>=0; i--) dat[i] = min(dat[2 * i + 1], dat[2 * i + 2]);
}

void update(){

}

// [i, j)の最小値を求める
// k: ノードの番号, dat[k]: [l, r)の最小値
int query(int i, int j, int k, int l, int r){
	// 交差していない
	if(j <= l || r <= i){
		return INF;
	//  [i, j)が[l, r)を完全に含む
	}else if(i <= l && r <= j){
		return dat[k];
	// 交差する
	}else{
		int lv = query(i, j, 2 * k + 1, l, (l + r) / 2);
		int rv = query(i, j, 2 * k + 2, (l + r) / 2, r);
		return min(lv, rv);
	}
}

int main(void){
	cin >> n >> a >> b;
	init();
	// rep(i, 2*n-1) cerr << dat[i] << endl;
	cout << query(a, b, 0, 0, n);
	return 0;
}