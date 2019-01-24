#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define rep(i, n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n;

signed main(){
    ll x, y;
    cin >> x >> y;
    ll t = y / x;
    ll cnt = 0;
    while(t >= 1){
        t /= 2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}