#include <bits/stdc++.h>
#define MAX_N 200001
#define mod  998244353
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, m, k;

// ax + by = gcd(a, b)
// if a = b*p + q then gcd(a, b) = gcd(b, q)
ll extgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1; y = 0; return a;
    } 
    ll p = a / b;
    ll g = extgcd(b, a - p * b, x, y);
    ll z = x - p * y;
    x = y; y = z;
    return g;
}

// assert m and a is prime with each other
inline ll modinv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    x %= m;
    if(x < 0) x += m;
    return x;
}

vector<ll> fact, inv_fact;
void init_fact(ll n) {
    fact.resize(n);
    fact[0] = 1;
    for(ll i=1; i<n; i++) {
        fact[i] = i * fact[i-1] % mod;
    }
    inv_fact.resize(n);
    inv_fact[n-1] = modinv(fact[n-1], mod);
    for (ll i=n-2; i>=0; i--) {
        inv_fact[i] = (i + 1) * inv_fact[i+1] % mod;
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

ll modpow(ll x, ll n) {
    if (n == 0) return 1;
    return modpow(x * x % mod, n / 2) * (n & 1 ? x : 1) % mod;
}

signed main(){
    cin >> n >> m >> k;
    init_fact(n);

    ll ret = 0;
    REP(i, k+1){
        ret += (((m * modpow(m - 1, n - 1 - i)) % mod) * nCr(n - 1, i)) % mod;
        ret %= mod;
    }
    cout << ret << endl;
    return 0;
}