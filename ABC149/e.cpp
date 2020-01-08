#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, m, s[MAX_N];
vector<ll> a;

signed main(){
    cin >> n >> m;
    a.resize(n);
    REP(i, n) cin >> a[i];
    sort(ALL(a));
    REP(i, n) s[i+1] = s[i] + a[i]; //s[0] = 0, s[1] = a[1], s[2] = a[1] + a[2],

    auto check = [&](ll v){
        ll num = 0, sum = 0;
        REP(i, n){
            ll pos = lower_bound(ALL(a), v-a[i]) - a.begin();
            num += n - pos;
            sum += s[n] - s[pos];
            sum += (n - pos) * a[i];
        }
        return P(num, sum);
    };

    int ok = 200001, ng = -1;
    while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if(check(mid).first <= m) ok = mid;
        else ng = mid;
    }
    // cout << ok  << " " << ng << endl;
    auto ret = check(ok);
    cout << ret.second + (m - ret.first) * (ok - 1) << endl; 
    // cout << m << " " << ret.first << " " << ok - 1 << endl;
    return 0;
}