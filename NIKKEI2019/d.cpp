#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#include <queue>
#define MAX_N 100001
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, m, d[MAX_N];
ll parent[MAX_N];
vector<ll> e[MAX_N], ev[MAX_N];
queue<ll> q;

signed main(){
    cin >> n >> m;
    rep(i, 0, n+m-1){
        ll a, b; cin >> a >> b;
        a--; b--;
        e[a].pb(b);
        ev[b].pb(a);
        parent[b] = a;
    }
    ll root = 0;
    while(ev[root].size() > 0){
        root = ev[root][0];
    }
    // cout << "root: " << root << endl;
    ll s = root;
    q.push(s);
    d[s] = 0;
    while(!q.empty()){
        for(ll childe: e[s]) d[childe] = max(d[s] + 1, d[childe]);
        s = q.front(); q.pop();
        for(ll ns :e[s]){
            q.push(ns);
        }
    }

    rep(b, 0, n){
        rep(j, 0, ev[b].size())
            if(d[ev[b][j]] > d[parent[b]]) parent[b] = ev[b][j];
    }

    rep(i, 0, n){
        if(i == root) cout << "0" << endl;
        else cout << parent[i] + 1<< endl;
    }
    return 0;
}
