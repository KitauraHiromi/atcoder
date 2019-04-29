#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n;
bool dp[101];

signed main(){
	cin >> n;
	dp[0] = true;
	for (int i = 1; i < 101; ++i){
		dp[i] = false;
		if(i >= 4) dp[i] |= dp[i-4];
		if(i >= 7) dp[i] |= dp[i-7];
	}
	if(dp[n]) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}