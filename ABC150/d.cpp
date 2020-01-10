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
ll n, m;
vector<ll> a;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

signed main(){
    cin >> n >> m;
    a.resize(n);
    REP(i, n) cin >> a[i];
    
    REP(i, n){
        a[i] /= 2;
    }

    ll k = a[0];
    REP(i, n-1){
        k = lcm(k, a[i+1]);
        if(k > m){
            cout << 0 << endl;
            return 0;
        }
    }
    REP(i, n){
        if((k / a[i]) % 2 == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << ((m / k) + 1) / 2 << endl;

    return 0;

}