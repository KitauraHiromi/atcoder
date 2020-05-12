#include <bits/stdc++.h>
#define MAX_N 200001
#define mod 1000000007
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n;
map<ll, ll> L, R;

signed main(){
    cin >> n;
    REP(i, n){
        ll a; cin >> a;
        ll l = i + a;
        ll r = i - a;
        if(L.count(l) != 1) L.insert(P(l, 1));
        else L[l]++;

        if(R.count(r) != 1) R.insert(P(r, 1));
        else R[r]++;
    }

    ll ret = 0;
    // ll check = 0;
    for(const auto& [key, value]: L){
        auto iterR = R.find(key);
        // check += value;
        // if(iterR != R.end()) cout << key << " " << value << " " << iterR->first << " "<< iterR->second << endl;
        if(iterR != R.end()) ret += value * iterR->second;
    }
    cout << ret << endl;

    return 0;
}