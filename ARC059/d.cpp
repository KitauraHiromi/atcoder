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
string s;

bool check(int i){
	return s[i] == s[i+1] || s[i+1] == s[i+2] || s[i+2] == s[i];
}

signed main(){
	cin >> s;
	n = s.size();

	if(n == 2){
		if(s[0] == s[1]){
			cout << "1 2" << endl;
			return 0;
		}else{
			cout << "-1 -1" << endl;
			return 0;
		}
	}else{
		for(int i=0; i<n-2; i++){
			if(check(i)){
				cout << i+1 << " " << i+3 << endl;
				return 0;
			}
		}
	}
	cout << "-1 -1" << endl;
    return 0;
}