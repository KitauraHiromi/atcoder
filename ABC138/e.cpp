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
ll n, sn, b[26];
string s, t;
vector<ll> a[26];

signed main(){
	cin >> s >> t;
	ll ret = 1;
	n = t.size(); sn = s.size();
	fill(b, b+26, 0);
	REP(i, sn) a[s[i] - 'a'].pb(i + 1);
	// REP(i, 26) for(ll e: a[i]) cout << e << endl;
	REP(i, n){
		int c = t[i] - 'a';
		// cout << c << endl;
		if(a[c].size() == 0){
			cout << -1 << endl;
			break;
		}
		// cout << i << " " << a[c][b[c]] << " " << b[c] << endl;
		if(a[c][b[c]] >= ret % sn){
			ret = (ret / sn) * sn + a[c][b[c]];
		}else{
			fill(b, b+26, 0);
			ret = (ret / sn + 1) * sn + a[c][b[c]];
		}
		if(a[c].size() > 1) b[c]++;
		if(i == n-1) cout << ret << endl;
	}
    return 0;
}