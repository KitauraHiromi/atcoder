#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 2001
#define MOD 1000000007
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, k, tree[MAX_N+1], a[MAX_N];

ll sum(ll i){
	ll ret = 0;
	while(i > 0){
		ret += tree[i];
		i -= i & -i;
	}
	return ret;
}

void add(ll i, ll x){
	while(i <= n){
		tree[i] += x;
		i += i & -i;
	}
}

ll rev_solve(){
	ll ans = 0;
	for(ll j=0; j<n; j++){
		ans += j - sum(a[j]);
		add(a[j], 1);
	}
	return ans;
}

ll rev_solve2(){
	ll ans = 0;
	for(ll i=0; i<n-1; i++){
		for(ll j=i+1; j<n; j++){
			if(a[i] > a[j]) ans++;
		}
	}
	return ans;
}


ll ord_solve2(){
	ll ans = 0;
	for(ll i=0; i<n-1; i++){
		for(ll j=i+1; j<n; j++){
			if(a[i] < a[j]) ans++;
		}
	}
	return ans;
}

signed main(){
	cin >> n >> k;
	REP(i, n) cin >> a[i];
	ll ret1 = rev_solve2();
	if(k % 2 == 0){
		ret1 *= k / 2;
		ret1 %= MOD;
		ret1 *= k + 1;
		ret1 %= MOD;
	}else{
		ret1 *= k;
		ret1 %= MOD;
		ret1 *= (k + 1)/2;
		ret1 %= MOD;
	}
	ll ret2 = ord_solve2();
	if(k % 2 == 0){
		ret2 *= k / 2;
		ret2 %= MOD;
		ret2 *= k - 1;
		ret2 %= MOD;
	}else{
		ret2 *= k;
		ret2 %= MOD;
		ret2 *= (k - 1)/2;
		ret2 %= MOD;
	}
	cout << (ret1 + ret2) % MOD << endl;
    return 0;
}