#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_X 100001
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, dp[MAX_X], x;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

signed main(){
	cin >> x;
	Fill(dp, 0);
	dp[0] = 1;
	for(int i=0; i<MAX_X; i++){
		if(i<100) continue;
		dp[i] |= dp[i-100];
		if(i<101) continue;
		dp[i] |= dp[i-101];
		if(i<102) continue;
		dp[i] |= dp[i-102];
		if(i<103) continue;
		dp[i] |= dp[i-103];
		if(i<104) continue;
		dp[i] |= dp[i-104];
		if(i<105) continue;
		dp[i] |= dp[i-105];
	}
	cout << dp[x] << endl;
    return 0;
}