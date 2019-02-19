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
// mapは使いづらい
map<ll, ll> s[2];

signed main(){
    cin >> n;
    rep(i, 0, n){
        ll v; cin >> v;
        int j;
        if(i%2) j = 0;
        else j = 1;
        if(s[j].find(v) != s[j].end()) s[j][v]++;
        else s[j].insert(P(v, 1));
    }
    ll m1[2], m2[2];
    m1[0] = m1[1] = m2[0] = m2[1] = -1;
    
    rep(i, 0, 2){
        for(auto e: s[i]){
            if(m1[i] == -1) m1[i] = e.first;
            else if(m2[i] == -1){
                m2[i] = e.first;
                if(s[i][m1[i]] < e.second) swap(m1[i], m2[i]); 
            }
            else if(s[i][m1[i]] <= e.second){
                m2[i] = m1[i];
                m1[i] = e.first;
            }
        }
    }
    ll ans;
    if(m1[0] != m1[1]){
        ans = n - s[0][m1[0]] - s[1][m1[1]];
    }
    // s[i][key]でkeyがない場合を書き出すのが手間
    // keyがない場合0を出すような配列でよい
    else{
        if(m2[0] != -1 && m2[1] != -1){
            ans = min(
                n - s[0][m2[0]] - s[1][m1[1]], 
                n - s[0][m1[0]] - s[1][m2[1]]
                );
        }else if(m2[0] != -1){
            ans = n - s[0][m2[0]] - s[1][m1[1]];
        }else if(m2[1] != -1){
            ans = n - s[0][m1[0]] - s[1][m2[1]];
        }else{
            ans = min(n - s[0][m1[0]], n - s[1][m1[1]]);
        }
    }
    cout << ans << endl;
    return 0;
}