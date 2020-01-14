#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
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
ll n, c[MAX_N];

ll modpow(ll x, ll n) {
    if (n == 0) return 1;
    return modpow(x * x % mod, n / 2) * (n & 1 ? x : 1) % mod;
}

ll modinv(ll a) {
    return modpow(a, mod - 2);
}

// assert m is prime
inline ll  inverse(ll  a, ll  m) {
    ll  b = m, x = 1, y = 0;
    // extgcd(a, m, x, y)
    while (b) {
        ll  t = a / b;
        swap(a -= t * b, b);
        swap(x -= t * y, y);
    }
    return (x % m + m) % m;
}


vector<ll> fact, inv_fact;
void init_fact(ll n) {
    fact.resize(n);
    fact[0] = 1;
    for (ll i = 1; i < n; i++) {
        fact[i] = i * fact[i - 1] % mod;
    }
    inv_fact.resize(n);
    inv_fact[n - 1] = inverse(fact[n - 1], mod);
    for (ll i = n - 2; i >= 0; i--) {
        inv_fact[i] = (i + 1) * inv_fact[i + 1] % mod;
    }
}

ll nPr(ll n, ll r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fact[n] * inv_fact[n - r] % mod;
}

ll nCr(ll n, ll r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

ll nHr(ll n, ll r) {
    if (n == 0 && r == 0) return 1;
    return nCr(n + r - 1, r);
}


ll mod_pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

signed main(){
    cin >> n;
    REP(i, n) cin >> c[i];
    sort(c, c+n);
    ll ret = 0;
    REP(i, n){
        ll add = (n - i + 1) * c[i] % mod;
        add *= modpow(2, 2*n-2);
        add %= mod;
        ret += add;
        ret %= mod;
    }
    cout << ret << endl;
    return 0;
}