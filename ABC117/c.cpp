#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define rep(i, n) for(int i=0; i<n; i++)
#define pb push_back
using namespace std;
typedef pair<int, int> P;
int n, m, x[MAX_N];

signed main(){
    cin >> n >> m;
    rep(i, m) cin >> x[i];
    if(n >= m){
        cout << 0 << endl;
        return 0;
    }
    sort(x, x+m);
    int dist[MAX_N], sod = m - 1;
    rep(i, sod) dist[i] = x[i+1] - x[i];
    sort(dist, dist+sod);
    int ret = 0;
    rep(i, m-n){
        ret += dist[i];
        // cout << dist[i] << " ";
    }
    // cout << endl;
    cout << ret << endl;
    return 0;
}