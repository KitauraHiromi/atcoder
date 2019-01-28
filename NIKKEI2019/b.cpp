#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n;
string a, b, c;

signed main(){
    cin >> n >> a >> b >> c;
    ll ret = 0;
    rep(i, 0, n){
        if(a[i]==b[i] && a[i]==c[i]) continue;
        else if(a[i]==b[i] || b[i]==c[i] || c[i]==a[i]) ret += 1;
        else ret += 2;
    }
    cout << ret << endl;
    return 0;
}
