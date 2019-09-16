#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, k, a[MAX_N];

signed main(){
	cin >> n >> k;
	REP(i, n) cin >> a[i];
	ll x = 0;
	ll tmp[45];
	REP(i, 45) tmp[i] = 0;
	REP(i, 45)
		REP(j, n)
			tmp[i] += (a[j] >> i) & 1LL;

	for(ll i=44; i>=0; i--)
		if(2*tmp[i] < n && (x | (1LL << i)) <= k)
			x |= 1LL << i;

	ll ans = 0;
	REP(i, n) ans += x ^ a[i];
	cout << ans << endl;
    return 0;
}