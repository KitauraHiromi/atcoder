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
ll n;
vector<ll> p, q, r;

signed main(){
    cin >> n;
    p.resize(n); q.resize(n); r.resize(n);
    REP(i, n) cin >> p[i];
    REP(i, n) cin >> q[i];

    r[0] = 1;
    REP(i, n-1) r[i+1] = r[i] + 1;

    ll a = 0, b = 0;
    bool flag_a = true, flag_b = true;
    do{
        if(!equal(p.begin(), p.end(), r.begin()) && flag_a) a++;
        else flag_a = false;

        if(!equal(q.begin(), q.end(), r.begin()) && flag_b) b++;
        else flag_b = false;
    } while(next_permutation(r.begin(), r.end()));
    cout << abs(a - b) << endl;
    return 0;
}