#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define MOD 1000000007
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, a[MAX_N], cnt[3];

signed main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];

	cnt[0] = 1;
	ll ret;
	if(a[0] == 0) ret = 3;
	else ret = 0;
	for(int i=1; i<n; i++){
		ll j = 0;
		bool cnt_flag = true;
		if(a[i] == cnt[0]){
			if(cnt_flag) cnt[0]++;
			j++;
			cnt_flag = false;
		}
		if(a[i] == cnt[1]){
			if(cnt_flag) cnt[1]++;
			j++;
			cnt_flag = false;
		}
		if(a[i] == cnt[2]){
			if(cnt_flag) cnt[2]++;
			j++;
			cnt_flag = false;
		}
		ret *= j;
		ret %= MOD;
	}
	cout << ret << endl;
    return 0;
}