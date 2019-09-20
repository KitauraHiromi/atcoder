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
const ll INF = 1LL << 62;

typedef pair<ll, ll> P;
ll n, x, a[MAX_N];

signed main(){
	cin >> n >> x;
	REP(i, n) cin >> a[i];
	ll min_cost[MAX_N]; fill(min_cost, min_cost+MAX_N, INF);

	ll ret = INF;
	REP(i, n){
		REP(j, n)
			min_cost[j] = min(min_cost[j], a[(j-i>=0) ? j-i : j-i+n]);
		ll tmp = 0;
		REP(j, n) tmp += min_cost[j];
		ret = min(ret, tmp + i * x);
	}
	cout << ret << endl;
    return 0;
}