#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 200001
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, p;

signed main(){
    cin >> n;
    ll cnt = 0, min_p = INF;
    REP(i, n){
        cin >> p;
        if(min_p >= p){
            cnt++;
            min_p = p;
        }
    }
    cout << cnt << endl;
    return 0;
}