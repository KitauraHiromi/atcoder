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
ll n;

signed main(){
	cin >> n;
	for(int i=1; i<MAX_N; i++){
		if((ll)floor(i * 1.08) == n){
			cout << i << endl;
			return 0;
		}
	}
	cout << ":(" << endl;
    return 0;
}