#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define all(v) v.begin(), v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n;

signed main(){
    int a, b, k; cin >> a >> b >> k;
    vector<int> v;
    rep(i, 1, 101){
        if(a%i==0 && b%i==0) v.pb(i);
    }
    reverse(all(v));
    cout << v[k-1] << endl;
    return 0;
}