#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 201
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
ll n, a[MAX_N][MAX_N];

signed main(){
	cin >> n;
	string s;
	REP(i, n){
		cin >> s;
		REP(j, n) a[i][j] = s[j] - '0';
	}
	ll ret = 0;
	REP(i, n){
		ll used[MAX_N]; REP(i, n) used[i] = -1;
		bool valid = true;
		vector<ll> group[MAX_N];
		group[0].pb(i);
		used[i] = 0;
		ll tmp = 0;
		REP(k, n){
			for(ll v: group[k]){
				REP(j, n){
					if(a[v][j] == 1){
						// cout << j << " " << used[j] << endl;
						if(used[j] >= 0 && used[j] < k-1) valid = false;
						else if(used[j] == k) valid = false;
						else if(used[j] == -1){
							used[j] = k + 1;
							group[k+1].pb(j);
							tmp = k + 1;
						}
						else if(used[j] == k-1) continue;
					}
				}
			}
		}
		// REP(j, n) cout << used[j] << endl; 
		REP(j, n) if(used[j] == -1) valid = false;
		if(valid) ret = max(ret, tmp);
	}
	if(ret == 0) cout << -1 << endl;
	else cout << ret + 1 << endl;

    return 0;
}