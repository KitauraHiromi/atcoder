#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 200001
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, k, p[MAX_N];
double expect[1010], expect_sum[MAX_N];

signed main(){
    cin >> n >> k;
    REP(i, n){
        cin >> p[i];
        p[i]--;
    }
    expect[0] = 1;
    REP(i, 1006){
        expect[i+1] = expect[i] + i + 2;
    }
    REP(i, 1005){
        expect[i] /= (double)(i + 1);
    }
    // REP(i, 1005) cout << expect[i] << endl;

    expect_sum[0] = expect[p[0]];
    REP(i, n){
        expect_sum[i+1] = expect_sum[i] + expect[p[i+1]];
    }
    // cout << expect_sum[n-1] << endl;
    double ret = -1;
    if(n-k > 0){
        REP(i, n-k){
            ret = max(ret, expect_sum[i+k] - expect_sum[i]);
        }
    }else{
        ret = expect_sum[n-1];
    }
    cout << ret << endl;
    
    return 0;
}
