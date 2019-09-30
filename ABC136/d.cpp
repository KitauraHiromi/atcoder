#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define MOD 1000000007
typedef long long ll;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef pair<ll, ll> P;
ll dp[13][MAX_N], n, a[MAX_N], b[MAX_N];
string s;

signed main(){
	cin >> s;
	n = s.size();
	// cout << (char)s[0] << " " << n << endl;
	b[0] = 1;
	REP(i, MAX_N) b[i+1] = b[i] * 10 % 13;

	REP(i, n) a[i] = s[n-i-1] - '0';
	REP(i, 13) REP(j, n+1) dp[i][j] = 0;

	if(s[n-1] != '?') dp[a[0]][1] = 1;
	else REP(i, 10) dp[i][1] = 1;

	FOR(i, 1, n){
		if(s[n-i-1] != '?') REP(k, 13){			
			dp[(a[i] * b[i] + k) % 13][i+1] += dp[k][i];
			dp[(a[i] * b[i] + k) % 13][i+1] %= MOD;
		}
		else{
			REP(j, 10) REP(k, 13){
				dp[(j * b[i] + k) % 13][i+1] += dp[k][i];
				dp[(j * b[i] + k) % 13][i+1] %= MOD;
			}
		}
	}
	cout << dp[5][n] << endl;
    return 0;
}