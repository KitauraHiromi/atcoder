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
ll n, m;
ll ret ;

signed main(){
	cin >> n >> m;
	ret = 0;
	ll i = 0;
	vector<ll> v;
	while(i < pow(m, n)){
		ll tmp = i, sum = 0;
		vector<ll> a;
		REP(j, n){
			a.pb(tmp % m + 1);
			sum += tmp % m + 1;
			tmp /= m;
		}
		// cout << a.size() << endl;
		// cout << "sum " << sum << endl;
		if(sum == m){
			FOR(j, 1, m+1){
				bool pass = true;
				REP(k, n){
					// cout << k << " " << a[k] << endl;
					if(a[k] % j != 0) pass = false;
					// cout << "flag" << endl;
				}
				// cout << j << endl;
				if(pass && ret < j){
					ret = j;
					v = a;
				}
			}
		}
		i++;
	}
	cout << ret << endl;
	REP(i, n) cout << v[i] << " ";
	cout << endl;
    return 0;
}