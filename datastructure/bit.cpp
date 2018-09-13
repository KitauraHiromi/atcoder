#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000001
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;
int tree[MAX_N + 1], a[MAX_N], n;
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
		rep(i, n) cerr << tree[i] << ' ';
		cerr << endl;
		ans += j - sum(a[j]);
		cerr << "ans:" <<  ans << endl;
		add(a[j], 1);
		cerr << "tree:";
		rep(i, n) cerr << tree[i] << ' ';
		cerr << endl;
	}
	cout << ans << endl;
}
int main(void){
	solve1();
}