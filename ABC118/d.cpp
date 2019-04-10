#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define INF 1000000000
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, m;
P a[9];

signed main(){
	cin >> n >> m;
	REP(i, m){
		cin >> a[i].first;
		switch(a[i].first){
			case 1:
				a[i].second = 2;
				break;
			case 2:
				a[i].second = 5;
				break;
			case 3:
				a[i].second = 5;
				break;
			case 4:
				a[i].second = 4;
				break;
			case 5:
				a[i].second = 5;
				break;
			case 6:
				a[i].second = 6;
				break;
			case 7:
				a[i].second = 3;
				break;
			case 8:
				a[i].second = 7;
				break;
			case 9:
				a[i].second = 6;
				break;
		}
	}
	sort(a, a+m, greater<P>());
	// REP(i, m) cout << a[i].first << " " << a[i].second << endl;
	int dp[MAX_N];
	dp[0] = 0;
	REP(i, n){
		dp[i + 1] = -INF;
		REP(j, m) if(i + 1 - a[j].second >= 0) dp[i + 1] = max(dp[i + 1 - a[j].second] + 1, dp[i + 1]);
	}
	// cout << dp[n] << endl;
	int k = n;
	REP(i, dp[n]){
		REP(j, m){
			if(k - a[j].second >= 0 && dp[k - a[j].second] == dp[k] - 1){
				cout << a[j].first;
				k -= a[j].second;
				break;
			}
		}
		// cout << k << " " << a[i].second << endl;
	}
	cout << endl;
    return 0;
}