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
ll n, k;
vector<P> e;

signed main(){
	cin >> n >> k;
	if(k > (n-1)*(n-2)/2) cout << -1 << endl;
	else{
		REP(i, n) FOR(j, i+1, n){
			if(e.size() >= n*(n-1)/2 - k) break;
			e.pb(P(i, j));
		}
		cout << e.size() << endl;
		for(P edge: e){
			cout << edge.first + 1 << " " << edge.second + 1 << endl;
		}


		// // check
		// set<P> tmp;
		// REP(i, n) FOR(j, i+1, n){
		// 	REP(l, k){
		// 		if(find(ALL(e), P(i, j)) == e.end() && find(ALL(e), P(j, i)) == e.end())
		// 			if(find(ALL(e), P(i, l)) != e.end() || find(ALL(e), P(l, i)) != e.end())
		// 				if(find(ALL(e), P(j, l)) != e.end() || find(ALL(e), P(l, j)) != e.end())
		// 					tmp.insert(P(i, j));
		// 	}
		// }
		// cout << tmp.size() << endl;
		// assert(k == tmp.size());
	}
    return 0;
}