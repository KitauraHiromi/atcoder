#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int n;
int cost[MAX_N][MAX_N];
bool used[MAX_N];



int prim(){
    int mincost[MAX_N], ret;
    rep(u, n){
        mincost[u] = INF;
        used[u] = false;
    }
    while(true){
        int v = -1;
        mincost[0] = 0;
        // XからV/Xへの最小コストの辺を張る頂点を探す
        rep(u, n){
            if(!used[v] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }

        if(v == -1) break;
        ret += mincost[v];
        used[v] = true;

        // vを加えたのでvにつながるmincostを更新
        rep(u, n){
            mincost[u] = min(mincost[u], cost[u][v]);
        }
    return ret;
}

int main(){
    rep
    return 0;
}