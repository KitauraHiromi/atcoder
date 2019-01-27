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

signed main(){
    int n;
    cin >> n;
    vector<int> v(n, 0), v2;
    rep(i, 0, n) cin >> v[i];
    rep(i, 0, (int)pow(2, n)){
        int bit = i;
        int ret = 0;
        rep(j, 0, n){
            if(bit%2 == 1) ret+=v[j];
            else ret-=v[j];
            bit/=2;
        }
        v2.pb(ret);
    }
    rep(i, 0, v2.size()) cout << v2[i]<< " ";
    cout << endl;

    int dp[5][30], m=15;
    rep(i, 0, 5) rep(j, 0, 30) dp[i][j] = 0;
    dp[0][m] = 1;
    rep(i, 0, 4){
        rep(j, -m, m){
            if(j+m-v[i] < 0 && j+m+v[i] < 30) dp[i+1][j+m] = dp[i][j+m+v[i]];
            else if(j+m-v[i] > 0 && j+m+v[i] > 30) dp[i+1][j+m] = dp[i][j+m-v[i]];
            else dp[i+1][j+m] = dp[i][j+m-v[i]] || dp[i][j+m+v[i]];
        }
    }
    rep(j, 0, 5){
        rep(i, 0, 30) cout << dp[j][i] << " ";
        cout << endl;
    }
    cout << dp[4][10+m] << endl;
    return 0;
}