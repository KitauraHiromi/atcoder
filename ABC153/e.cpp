#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 1001
#define MAX_H 10010
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll h, n, dp[MAX_H], a[MAX_N], b[MAX_N];

signed main(){
    cin >> h >> n;
    for(ll i=1; i<=n; i++) cin >> a[i] >> b[i];

    REP(j, MAX_H){
        if(j == 0) dp[j] = 0;
        else dp[j] = INF;
    }
    // REP(j, MAX_H) cout << dp[j] << " ";
    // cout << endl;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=MAX_H; j++){
            dp[j] = min(dp[j], dp[max(0LL, j-a[i])] + b[i]);
        }
    }
    // REP(j, h+1) cout << dp[j] << " ";
    // cout << endl;
    cout << dp[h] << endl;
    return 0;
}