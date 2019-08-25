#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define MOD 1000000007
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n;
string s;
bool d[2*MAX_N];

signed main(){
	cin >> n >> s;
	d[0] = 1;
	for(ll i=1; i<2*n; i++){
		if(s[i] == s[i-1]) d[i] = 1 - d[i-1];
		else d[i] = d[i-1];
	}
	// for(ll i=0; i<2*n; i++){
	// 	if(d[i]) cout << 'L';
	// 	else cout << 'R';
	// }
	ll ret = 1;
	ll num_l = 1;
	for(ll i=1; i<2*n; i++){
		if(d[i]) num_l++;
		else{
			ret *= num_l--;
			ret %= MOD;
		}
	}
	if(num_l != 0) ret = 0;
	if(s[0] == 'W') ret = 0;
	// cout << ret << endl;
	ret %= MOD;
	for(ll i=1; i<=n; i++){
		ret *= i;
		ret %= MOD;
	}
	cout << ret << endl;
    return 0;
}