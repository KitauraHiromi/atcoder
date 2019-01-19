#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 200001
#define INF 100000000000
#define rep(i, n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, d, a[MAX_N];

signed main(){
    cin >> n >> d;
    ll sum = 0;
    rep(i, n) cin >> a[i];
    rep(i, n) sum += a[i];
    sum *= 2;

    ll ret = INF;
    for(ll i=0; i<n-1; i++)
        for(ll j=i+1; j<n; j++){
            ll cost = sum - a[i] - a[j];
            cost += ((i - 1) + (n - 1) + (n - j)) * d;
            ret = min(ret, cost);
    }
    cout << ret << endl;
    return 0;
}