#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MAX_N 10001
#define MAX_C 10001
using namespace std;

const int ST_SIZE = (1 << 15) - 1;
// 入力
int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_N];

// セグメント木のデータ
double vx[ST_SIZE], vy[ST_SIZE]; // 各接点のベクトル
double ang[ST_SIZE]; // 各接点の角度

// 角度の変化を調べるため、現在の角度を保存しておく
double prv[MAX_N];

// セグメント木を初期化する
// kは節点の番号、	l, rはその接点が[l, r)に対応づいていることを表す
void init(int k, int l, int r){
	ang[k] = vx[k] = 0.0;
	if(r - l == 1){
		// 葉
		vy[k] = L[l];
	}else{
		// 葉でない節点
		int chl = k * 2 + 1, chr = k * 2 + 2;
		init(chl, l, (l + r) / 2);
		init(chr, (l + r) / 2, r);
		vy[k] = vy[chl] + vy[chr];		
	}
}

// 場所sの角度がaだけ変更になった
// vは節点の番号, l, rはその節点が[l, r)に対応づいていることを表す
void change(int s, double a, int v, int l, int r){
	if(s <= l) return;
	else if(s < r){
		int chl = v * 2 + 1, chr = v * 2 + 2;
		int m = (l + r) / 2;
		change(s, a, chl, l, m);
		change(s, a, chr, m, r);
		if(s <= m) ang[v] += a;

		double s = sin(ang[v]), c = cos(ang[v]);
		vx[v] = vx[chl] + (c * vx[chr] - s * vy[chr]);
		vy[v] = vy[chl] + (s * vx[chr] + c * vy[chr]);
	}
}

void solve(){
	init(0, 0, N);
	for(int i=1; i<N; i++) prv[i] = M_PI;

		// 各クエリを処理
		for(int i=0; i<C; i++){
			int s = S[i];
			double a = A[i] / 360.0 * 2 * M_PI; // ラジアンに直す

			change(s, a - prv[s], 0, 0, N);
			prv[s] = a;
			cout << vx[0] << ' ' <<  vy[0] << endl;
		}
}

int main(void){
	solve();
}