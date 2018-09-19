#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000001
#define MAX_Q 1000001
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;
int tree[MAX_N + 1], a[MAX_N], n, q;
int sum(int i){
	int ret = 0;
	// i-=i&-i: 最下位ビットを削除
	for(; i>0; i-=i&-i) ret += tree[i];
	return ret;
}

void add(int i, int x){
	for(; i<=n; i+=i&-i) tree[i] += x;
}

// バブルソートの交換回数 = 反転数
void solve1(){
	cin >> n;
	rep(i, n) cin >> a[i];
	ll ans = 0;
	rep(j, n){
		cerr << "j:" << j << " a[j]:" << a[j] << " sum:" << sum(a[j]) << endl;
		cerr << "tree:";
		rep(i, n+1) cerr << tree[i] << ' ';
		cerr << endl;
		ans += j - sum(a[j]);
		cerr << "ans:" <<  ans << endl;
		add(a[j], 1);
		cerr << "tree:";
		rep(i, n+1) cerr << tree[i] << ' ';
		cerr << endl;
	}
	cout << ans << endl;
}

ll sum(ll *b, int i){
	ll ret = 0;
	for(; i>0; i-=i&-i) ret += b[i];
	return ret;
}

void add(ll *b, int i, int v){
	for(; i<=n; i+=i&-i) b[i] += v;
}

// A simple Problem with integers (POJ3468)
ll bit0[MAX_N + 1], bit1[MAX_N + 1];
int A[MAX_N], L[MAX_Q], R[MAX_Q], X[MAX_Q];
char T[MAX_Q];

void solve2(){
	cin >> n;
	for(int i=1; i<n; i++) add(bit0, i, a[i]);
	for(int i=0; i<q; i++){
		if(T[i] == 'C'){
			add(bit0, L[i], -X[i] * (L[i] - 1));
			add(bit1, L[i], X[i]);
			add(bit0, R[i] + 1, X[i] * R[i]);
			add(bit1, R[i] + 1, -X[i]);
		}else{
			ll res = 0;
			res += sum(bit0, R[i]) + sum(bit1, R[i]) * R[i];
			res -= sum(bit0, L[i] - 1) + sum(bit1, L[i] - 1) * (L[i] - 1);
			cout << res << endl;
		}
	}

}
int main(void){
	solve1();
}