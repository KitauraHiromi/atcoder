#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 101
#define rep(i, n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, h[MAX_N];

signed main(){
    cin >> n;
    ll ret = 0;
    h[0] = 0;
    rep(i, n){
        cin >> h[i+1];
        ll d = h[i+1] - h[i];
        ret += (d>0) ? d: 0;
    }
    cout << ret << endl;

    return 0;
}