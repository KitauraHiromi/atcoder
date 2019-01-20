#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define INF 1000000001
#define MAX_N 10001
#define MAX_M 200001
#define rep(i, n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;
ll n, m;
ll cost[MAX_N][MAX_N];
bool used[MAX_N];

ll prim(){
    ll mincost[MAX_N], ret;
    ret = 0;
    rep(u, n){
        mincost[u] = INF;
        used[u] = false;
    }
    mincost[0] = 0;
    while(true){
        ll v = -1;
        // XからV/Xへの最小コストの辺を張る頂点を探す
        rep(u, n){
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }

        if(v == -1) break;
        ret += mincost[v];
        used[v] = true;

        // vを加えたのでvにつながるmincostを更新
        rep(u, n){
            mincost[u] = min(mincost[u], cost[u][v]);
        }
    }
    return ret;
}

signed main(){
    cin >> n >> m;
    rep(i, n) rep(j, n) if(i != j) cost[i+1][j+1] = INF;
    rep(i, n){
        ll c;
        cin >> c;
        cost[0][i+1] = c;
        cost[i+1][0] = c;
    }
    rep(i, m){
        ll a, b, r;
        cin >> a >> b >> r;
        cost[a][b] = r;
        cost[b][a] = r;
    }
    n += 1;
    cout << prim() << endl;
    return 0;
}