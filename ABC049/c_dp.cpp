#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n;
int dp[MAX_N];
string s;
string a[4] = {"dream", "dreamer", "erase", "eraser"};

signed main(){
    cin >> s;
    dp[0] = 1;
    n = s.size();
    rep(i, 1, n+1){
        rep(j, 0, 4){
            int k = a[j].size();
            if(i-k < 0) continue;
            if(dp[i-k] && s.substr(i-k, k) == a[j]) dp[i] = 1;
        }
    }
    // rep(i, 0, n+1) cout << dp[i];
    if(dp[n] == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}