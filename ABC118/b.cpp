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
ll n, m;
#define MAX_M 31
int v[MAX_M];

signed main(){
    cin >> n >> m;
    rep(i, 0, MAX_M) v[i] = 1;
    rep(i, 0, n){
        ll k; cin >> k;
        int w[MAX_M] = {};
        rep(j, 0, k){
            ll a; cin >> a;
            w[a-1] = 1;
        }
        rep(j, 0, m){
            v[j] = min(w[j], v[j]);
        }
    }
    int ret = 0;
    rep(i, 0, m){
        if(v[i] == 1) ret++;
    }
    cout << ret << endl;
    return 0;
}