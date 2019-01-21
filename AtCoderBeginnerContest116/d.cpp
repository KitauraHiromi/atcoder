#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define rep(i, n) for(ll i=0; i<n; i++)
#define repq(i, k, n) for(ll i=k; i<n; i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, k;
P s[MAX_N];
vector<P> p, q; // 取ったダブリ寿司, 取っていない新規寿司
set<ll> t; // 取った寿司の種類を記録

signed main(){
    cin >> n >> k;
    rep(i, n){
        ll t, d;
        cin >> t >> d;
        s[i] = P(d, t);
    }
    sort(s, s+n, greater<P>());
    ll ts = 0;
    rep(i, k){
        ts += s[i].first;
        if(t.find(s[i].second) != t.end()) p.pb(s[i]);
        else t.insert(s[i].second);
    }
    reverse(p.begin(), p.end());
    ll x = t.size();
    repq(i, k, n){
        if(t.find(s[i].second) != t.end());
        else q.pb(s[i]);
    }

    ll ret = ts;
    rep(i, min(p.size(), q.size())){
        ret = max(ret, ts + x * x);
        ts += q[i].first - p[i].first;
        x++;
    }
    ret = max(ret, ts + x * x);
    cout << ret << endl;
    return 0;
}