#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 200001
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n;

ll bit[MAX_N+1];

void init(ll _n){
    memset(bit, 0, _n+1);
}

void add(ll x, ll a){
    for(ll i=x; i<=n; i+=i&-i) bit[i] += a;
}

ll sum(ll x){
    ll ret = 0;
    for(ll i=x; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

signed main(){
    string s; cin >> s;
    vector<ll> a[26];
    n = s.size();
    rep(i, 0, n){
        a[s[i]-'a'].pb(i);
    }
    ll odd = 0;
    rep(i, 0, 26){
        if(a[i].size()%2 == 1) odd++;
    }
    if(odd>=2){
        cout << -1 << endl;
        return 0;
    }

    string l, m, r;
    ll idx[26];
    rep(i, 0, n){
        ll j = s[i]-'a';
        if(a[j].size()%2 == 1){
            if(idx[j]<a[j].size()/2) l += s[i];
            else if(idx[j]==a[j].size()/2) m += s[i];
            else r += s[i];
        }
        else{
            if(idx[j]<a[j].size()/2) l += s[i];
            else r += s[i];
        }
        idx[s[i]-'a']++;
    }
    string kaibun = l + m;
    reverse(l.begin(), l.end());
    kaibun += l;
    // cout << kaibun << endl;

    ll b[MAX_N], idx2[26];
    rep(i, 0, n){
        ll j = kaibun[i] - 'a';
        b[i] = a[j][idx2[j]];
        idx2[j]++;
    }
    // rep(i, 0, n) cout << b[i] << " ";
    // cout << endl;
    // init(n);
    ll ret = 0;
    for(ll i=0; i<n; i++){
        ret += i - sum(b[i]+1);
        add(b[i]+1, 1);
    }
    cout << ret << endl;
    return 0;
}