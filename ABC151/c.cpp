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
ll n, m, cnt[MAX_N];
bool ac[MAX_N];

signed main(){
    cin >> n >> m;
    REP(i, m){
        string s;
        ll p;
        cin >> p >> s;
        if(s == "WA" && !ac[p-1]) cnt[p-1]++;
        else if(s == "AC") ac[p-1] |= true;
    }
    ll cnt_ac = 0, cnt_wa = 0;
    REP(i, n){
        if(ac[i]){
            cnt_ac++;
            cnt_wa += cnt[i];
        }
    }
    cout << cnt_ac << " " << cnt_wa << endl;
    return 0;
}