#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 1001
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, k, a[MAX_N], b[MAX_N+1];

signed main(){
	cin >> n >> k;
	REP(i, n) cin >> a[i];
	fill(b, b+MAX_N, 0);
	b[0] = 0;
	for(ll i=1; i<=n; i++) b[i] += a[i-1] + b[i-1];
	
	ll ret = 0;
	for(ll i=50; i>=0; i--){
		ll cnt = 0;
		for(ll j=0; j<n-1; j++){
			for(ll k=j+1; k<n; k++){
				// cout << ((b[k+1] - b[j+1]) & (1LL << i)) << endl;
				if(((b[k+1] - b[j+1]) & (1LL << i)) != 0) cnt++;
			}
		}
		cout << cnt << endl;
		if(cnt >= k) ret |= 1LL << i;
	}

	cout << ret << endl;
    return 0;
}