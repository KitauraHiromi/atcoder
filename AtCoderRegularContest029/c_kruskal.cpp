#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#include <queue>
#define MAX_N 100001
#define MAX_M 200001
#define rep(i, n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Q;
ll n, m, par[MAX_N];
priority_queue< Q, vector<Q>, greater<Q>> q;

// Union Find
void init(ll _n){
    rep(i, _n) par[i] = i;
}

ll root(ll x){
    if(par[x] == x) return x;
    else return par[x] = root(par[x]);
}

bool same(ll x, ll y){
    return root(x) == root(y);
}

void unit(ll x, ll y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    else par[x] = y;
}

ll kruskal(ll _n){
    init(_n);
    ll ret = 0;
    while(!q.empty()){
        Q top = q.top();
        q.pop();
        ll c, a, b;
        c = top.first;
        a = top.second.first;
        b = top.second.second;
        if(same(a, b)) continue;
        unit(a, b);
        ret += c;
    }
    return ret;
}

signed main(){
    cin >> n >> m;
    rep(i, n){
        ll c;
        cin >> c;
        q.push(Q(c, P(0, i+1)));
    }
    rep(i, m){
        ll a, b, r;
        cin >> a >> b >> r;
        q.push(Q(r, P(a, b)));
    }
    cout << kruskal(n+1) << endl;
    return 0;
}