#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 301
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
ll n, a[MAX_N][MAX_N];

signed main(){
	cin >> n;
	ll ret = 0;
	bool ans = true;
	REP(i, n) REP(j, n){ cin >> a[i][j]; ret += a[i][j]; }
	ret /= 2;

	REP(i, n) FOR(j, i, n){
		bool once = true;
		REP(k, n){
			if(i == j || i == k || j == k) continue;
			ans &= (a[i][k] + a[k][j] >= a[i][j]);
			if(a[i][k] + a[k][j] == a[i][j] && once){
				ret -= a[i][j];
				once = false;
			}
		}
	}

	if(ans) cout << ret << endl;
	else cout << -1 << endl;

    return 0;
}