#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define MAX_A 100001
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, m, max_b[MAX_N], now[MAX_N];
vector<ll> v[MAX_A];
// priority_queue<ll, vector<ll>, greater<ll>> q;
priority_queue<ll> q;

signed main(){
	cin >> n >> m;
	ll ret = 0;
	REP(i, n){ ll a, b; cin >> a >> b; v[a].pb(b); }
	FOR(i, 1, m+1){
		for(auto e: v[i]){
			q.push(e);
		}
		if(!q.empty()){
			ret += q.top();
			q.pop();
		}
	}
	cout << ret << endl;

    return 0;
}