#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_H 21
#define MAX_W 21
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 1000;
ll h, w, d[400][400];
char s[MAX_H][MAX_W];
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

signed main(){
    cin >> h >> w;
    REP(i, h) REP(j, w) cin >> s[i][j];
    REP(i, h*w) REP(j, h*w){
        if(i == j) d[i][j] = 0;
        else d[i][j] = INF;
    }
    REP(i, h*w){
        ll x = i % h;
        ll y = i / h;
        REP(j, 4){
            ll nx = x + dx[j];
            ll ny = y + dy[j];
            if(0 <= nx && nx < h && 0 <= ny && ny < w){
                if(s[x][y] == '.' && s[nx][ny] == '.'){
                    d[i][ny*h+nx] = 1;
                }
            }
        }
    }



    //warshall_floyd
    REP(k, h*w) REP(i, h*w) REP(j, h*w) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    ll ret = 0;
    REP(i, h*w) REP(j, h*w){
        if(d[i][j] != INF) ret = max(ret, d[i][j]);
    }
    cout << ret << endl;
    return 0;
}