#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define pb push_back
#define ALL(v) (v).begin(),(v).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n;

signed main(){
    cin >> n;
    ll v1[MAX_N], v2[MAX_N];
    rep(i, 0, MAX_N) v1[i] = v2[i] = 0;
    rep(i, 0, n){
        ll v; cin >> v;
        if(i%2==0) v1[v]++;
        else v2[v]++;
    }
    vector<P> pv1, pv2;
    rep(i, 1, MAX_N){
        pv1.pb(P(v1[i], i));
        pv2.pb(P(v2[i], i));
    }
    sort(ALL(pv1), greater<P>());
    sort(ALL(pv2), greater<P>());

    ll ans;
    if(pv1[0].second != pv2[0].second)
        ans = n - pv1[0].first - pv2[0].first;
    else
        ans = n - max(pv1[0].first + pv2[1].first, pv1[1].first + pv2[0].first);
    cout << ans << endl;
    return 0;
}