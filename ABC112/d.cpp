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
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, m, ret;

void solve(ll i){
	if(m - i * (n - 1) > 0){
		if((m - i * (n - 1)) % i == 0) ret = max(ret, i);
	}
}

signed main(){
	cin >> n >> m;
	ret = 0;
	for(ll i=1; i*i<=m; i++){
		solve(i);
		solve(m/i);
	}
	cout << ret << endl;
    return 0;
}