#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 1001
#define MAX_N2 MAX_N*(MAX_N+1)/2
typedef long long ll;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef pair<ll, ll> P;
ll n, k, a[MAX_N], c[50];
vector<ll> b;
bool use[MAX_N2];

signed main(){
	cin >> n >> k;
	REP(i, n){
		cin >> a[i];
	}
	// fill(a, a+n, 1);
	for(ll r=0; r<n; r++){
		for(ll l=r; l<n; l++){
			b.pb(0);
			for(ll i=r; i<=l; i++) b[b.size()-1] += a[i];
		}
	}
	ll bn = b.size();

	fill(use, use+bn, true);
	fill(c, c+50, 0);

	// cout << bn << endl;
	ll ret = 0;
	for(ll j=49; j>=0; j--){
		bool tmp_use[MAX_N2]; fill(tmp_use, tmp_use+MAX_N2, true);
		REP(i, bn){
			tmp_use[i] = use[i];
			tmp_use[i] &= ((b[i] >> j) & 1); 
			if(tmp_use[i]){
				c[j]++;
				// cout << b[i] << endl;
			}
		}
		// cout << c[j] << endl;
		if(c[j] >= k){
			REP(l, bn) use[l] &= tmp_use[l];
			ret += 1LL << j;
		}
	}
	cout << ret << endl;
    return 0;
}