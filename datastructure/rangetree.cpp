#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
#define MAX_M 5001
const int ST_SIZE = (1 << 18) - 1;

// 入力
int N, M;
int A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];

int nums[MAX_N]; // Aをソートしたもの
vector<int> dat[ST_SIZE]; // セグメント木のデータ

// セグメント木を構築する
// kは節点番号で、区間[l, r)に対応する
void init(int k, int l, int r){
	if(r - l == 1){
		dat[k].push_back(A[l]);
	}else{
		int lch = k * 2 + 1, rch = k * 2 + 2;
		init(lch, l, (l + r) / 2);
		init(rch, (l + r) / 2, r);
		dat[k].resize(r - l);

		// STLのmerge関数を用いて、子の二つの列をマージ
		merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
	}
}

// [i, j)のx以下の数の個数を数える
// kは節点の個数で、区間[l, r)に対応する
int query(int i, int j, int x, int k, int l, int r){
	if(j <= l || r < i){
		// 完全に交差しない
		return 0;
	}else if(i <= l && r <= j){
		// 完全に含まれる
		return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
	}else{
		// 子について再帰的に求める
		int lc = query(i, j, x, k * 2 + 1, l, (l + r) / 2);
		int rc = query(i, j, x, k * 2 + 2, (l + r) / 2, r);
		return lc + rc;
	}
	
}

void solve(){
	for(int i=0; i<N; i++) nums[i] = A[i];
	sort(nums, nums + N);
	init(0, 0, N);
	for(int i=0; i<M; i++){
		// [l, r)のk番目を探す
		int l = I[i], r = J[i] + 1, k = K[i];

		int lb = -1, ub = N - 1;
		while(ub - lb > 1){
			int md = (ub + lb) / 2;
			int c = query(l, r, nums[md], 0, 0, N);
			if(c >= k) ub = md;
			else lb = md;
		}
		cout << nums[ub] << endl;
	}
}

int main(){
	solve();
}