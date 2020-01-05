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

signed main(){
	cin >> s;
	int ret = 0;
	for(int i=0; i<1000; i++){
		int index = 0;
		// keta[0] = i / 100;
		// keta[1] = (i - keta[0]) / 10;
		// keta[2] = i % 10;
		string keta = s.to_string();
		for(char c: s){
			// int a = c - '0';
			if(keta[indes] == c){
				index++;
		if(index > 3){
					break;
				}
			}
		}
			ret++;
	}
	cout << ret << endl;
    return 0;
}