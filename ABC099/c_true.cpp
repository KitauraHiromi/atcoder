#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define INF 1000000001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, dp[MAX_N];

signed main(){
	cin >> n;
	dp[0] = 0;
	for(int i=1; i<=n; i++){
		dp[i] = INF;
		int j = 1;
		while(i >= j){
			dp[i] = min(dp[i-j] + 1, dp[i]);
			j *= 6;
		}
		j = 1;
		while(i >= j){
			dp[i] = min(dp[i-j] + 1, dp[i]);
			j *= 9;
		}
	}
	cout << dp[n] << endl;
    return 0;
}