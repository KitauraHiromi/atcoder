#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
ll n, m, e[MAX_N][2], b[MAX_N];
vector<ll> ret;

ll par[MAX_N]; // 親の番号

// n要素で初期化
void init(ll n){
	for(ll i=0; i<n; i++) par[i] = i;
}

// 木の根を求める
ll root(ll x){
	if(par[x] == x){
		return x;
	}else{
		return par[x] = root(par[x]); // 経路圧縮
	}
}

bool same(ll x, ll y){
	return root[x] == root[y];
}

void unit(ll x, ll y){
	x = root(x);
	y = root(y);
	if(x==y) return;
	par[x] = y;
}

signed main(){
	cin >> n >> m;
	REP(i, m){ cin >> e[i][0] >> e[i][1]; e[i][0]--; e[i][1]--; }
	init(n);
	ll x = n * (n-1) / 2;
	fill(b, b+n, 1LL);
	ret.pb(x);
	for(ll i=m-1; i>=0; i--){
		// ll ass = 0;
		// REP(i, n) ass += b[i];
		// REP(i, n) cout << b[i] << endl;
		// cout << endl;
		// assert(ass == n);
		if(same(root(e[i][0]), root(e[i][1])))
			ret.pb(ret.back());
		else{
			// assert(b[root(e[i][0])] != 0);
			// assert(b[root(e[i][1])] != 0);
			ll y = b[root(e[i][0])];
			ll z = b[root(e[i][1])];
			x = x + y * (y-1) / 2 + z * (z-1) / 2 - (y+z) * (y+z-1) / 2;
			b[root(e[i][0])] += b[root(e[i][1])];
			b[root(e[i][1])] = 0;
			unit(e[i][1], e[i][0]);
			// ll tmp = 0;
			// REP(i, n) tmp += b[i] * (b[i] - 1) / 2;
			ret.pb(x);
		}		
	}
	reverse(ALL(ret));
	FOR(i, 1, m+1){
		cout << ret[i] << endl;
	}
    return 0;
}