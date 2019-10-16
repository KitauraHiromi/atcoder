#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define MAX_N 51
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, k, x[MAX_N], y[MAX_N];

signed main(){
	cin >> n >> k;
	REP(i, n) cin >> x[i] >> y[i];
	ll ret = INF;
	// x
	REP(i, n){
		REP(j, n){
			// y
			REP(l, n){
				REP(m, n){
					ll cnt = 0;
					REP(p, n) if((x[p] - x[i]) * (x[p] - x[j]) <= 0 && (y[p] - y[l]) * (y[p] - y[m]) <= 0) cnt++;
					// cout << cnt << endl;
					if(cnt >= k) ret = min(ret, abs(x[i] - x[j]) * abs(y[l] - y[m]));
				}
			}
		}
	}
	cout << ret << endl;
    return 0;
}