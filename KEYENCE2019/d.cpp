#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 1001
#define MAX_M 1001
#define MOD 1000000007
#define rep(i, n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, m, a[MAX_N], b[MAX_M], g[MAX_N][MAX_M];

bool check(vector<ll> v){

    rep(i, n){
        ll max_i = 0;
        rep(j, m) max_i = max(max_i, v[i*m + j]);
        if(max_i != a[i]) return false;
    }
    rep(j, m){
        ll max_j = 0;
        rep(i, n){
            max_j = max(max_j, v[i*m + j]);
        }
        if(max_j != b[j]) return false;
    }
    return true;
}

void solve(){
    vector<ll> c(n*m+1, 0);
    rep(i, n) c[a[i]]+=3;
    rep(j, m) c[b[j]]+=1;

    ll ret = 1;
    for(ll i=n*m; i>0; i--){
        if(c[i] == 4) 
            // 両方に現れる場合
            ret *= 1;
        else if(c[i] == 3){
            // aに現れる場合
            ll tmp = 0;
            rep(j, m) if(b[j]>=i) tmp++;
            ret *= tmp;
            ret %= MOD;
        }else if(c[i] == 1){
            // bに現れる場合
            ll tmp = 0;
            rep(j, n) if(a[j]>=i) tmp++;
            ret *= tmp;
            ret %= MOD;
        }else if(c[i] == 0){
            ll tmp1 = 0;
            rep(j, m) if(b[j]>=i) tmp1++;
            ll tmp2 = 0;
            rep(j, n) if(a[j]>=i) tmp2++;
            ret *= (tmp1*tmp2%MOD - n*m + i);
            ret %= MOD;
        }else{
            cout << 0 << endl;
            return;
        }
    }
    cout << ret << endl;
}

signed main(){
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    solve();

    // vector<ll> v(n*m);
    // iota(v.begin(), v.end(), 1);
    // ll ret = 0;
    // while(next_permutation(v.begin(), v.end())){

    //     if(check(v)){
    //         rep(i, n){
    //             rep(j, m) cout << v[i*m + j] << " ";
    //             cout << endl;
    //         }
    //         ret++;
    //     }
    // }
    // cout << ret << endl;
    return 0;
}