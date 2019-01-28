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
ll n, m, parent[MAX_N], h[MAX_N]; //入次数を管理
vector<ll> e[MAX_N], ev[MAX_N];

signed main(){
    cin >> n >> m;
    rep(i, 0, MAX_N) h[i] = 0;
    rep(i, 0, n+m-1){
        ll a, b; cin >> a >> b;
        a--; b--;
        e[a].pb(b);
        ev[b].pb(a);
        h[b]++;
        parent[b] = a;
    }

    // 入次数が0の頂点集合
    stack<ll> st;

    // 入次数が0の頂点があればstに追加
    rep(i, 0, n) if(h[i]==0) st.push(i);

    vector<ll> v;
    while(!st.empty()){
        // rep(i, 0, n) cout << h[i] << " ";
        // cout << endl;
        ll t = st.top(); st.pop();
        v.pb(t);
        rep(i, 0, e[t].size()){
            h[e[t][i]]--;
            if(h[e[t][i]]==0) st.push(e[t][i]);
        }
    }

    // rep(i, 0, v.size()) cout << v[i] + 1 << " ";
    // cout << endl;

    ll d[MAX_N];
    rep(i, 0, n) d[v[i]] = i;
    rep(b, 0, n){
        rep(j, 0, ev[b].size())
            if(d[ev[b][j]] > d[parent[b]]) parent[b] = ev[b][j];
    }
    rep(i, 0, n){
        if(i == v[0]) cout << "0" << endl;
        else cout << parent[i] + 1<< endl;
    }
    return 0;
}