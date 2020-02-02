#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 10001
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
ll n, g[MAX_N], l[MAX_N], a[MAX_N];
map<ll, ll> pf[MAX_N];

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

map<ll, ll> prime_factor(ll a){
    map<ll, ll> ret;
    for(ll p=2; p*p<=a; p++){
        while(a % p == 0){
            a /= p;
            ret[p]++;
        }
    }
    if(a != 1) ret[a] = 1;
    return ret;
}

signed main(){
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) pf[i] = prime_factor(a[i]);
    map<ll, ll> max_factor;
    REP(i, n) for(auto p: pf[i]) max_factor[p.first] = max(max_factor[p.first], p.second);
    ll l = 1;
    for(auto p: max_factor){
        l *= modpow(p.first, p.second);
        l %= mod;
    }
    // cout << l << endl;
    ll ret = 0;
    REP(i, n){
        ret += l * modinv(a[i]);
        ret %= mod;
    }
    cout << ret << endl;
    
    return 0;
}