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
ll n, h, a[MAX_N], b[MAX_N];

signed main(){
	cin >> n >> h;
	ll max_a = 0, ret = 0;
	REP(i, n){
		cin >> a[i] >> b[i];
		max_a = max(max_a, a[i]);
	}
	sort(b, b+n, greater<ll>());
	REP(i, n){
		if(b[i] > max_a){
			h -= b[i];
			ret++;
		}
		if(h <= 0) break;
	}
	if(h > 0) ret += (h % max_a == 0) ? h / max_a : h / max_a + 1;
	cout << ret << endl;

    return 0;
}