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
string s[MAX_N];
map<string, ll> m;

signed main(){
    cin >> n;
    REP(i, n) cin >> s[i];
    REP(i, n){
        m[s[i]]++;
    }
    ll max_cnt = 0;
    vector<string> vs;
    for(const auto& kv: m){
        // cout << kv.first << " " << kv.second << endl;
        max_cnt = max(max_cnt, kv.second);
    }
    for(const auto& kv: m){
        if(kv.second == max_cnt) vs.pb(kv.first);
    }
    sort(vs.begin(), vs.end());
    for(auto& str: vs) cout << str << endl;
    return 0;
}