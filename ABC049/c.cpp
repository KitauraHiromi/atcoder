#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define ALL(v) v.begin(), v.end()
#define MAX_N 100001
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n;
string s;
string a = "dream", b = "dreamer", c = "erase", d = "eraser";
signed main(){
    cin >> s;
    reverse(ALL(s));
    reverse(ALL(a));
    reverse(ALL(b));
    reverse(ALL(c));
    reverse(ALL(d));
    int i = 0, n = s.size();
    while(i < n){
        if(s.substr(i, a.size()) == a) i += a.size();
        else if(s.substr(i, b.size()) == b) i += b.size();
        else if(s.substr(i, c.size()) == c) i += c.size();
        else if(s.substr(i, d.size()) == d) i += d.size();
        else break;
    }
    if(i == n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}