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
unordered_map<double, double> m;
// ll f1(ll n){
//     return n / 2;
// }

// ll f2(ll n){
//     return 3 * n + 1;
// }

signed main(){
    ll s;
    cin >> s;
    m[s] = 1;
    rep(i, 1000000){
        // if(s % 2 == 0) s = f1(s);
        // else s = f2(s);
        s = (s % 2) ? s / 2 : 3 * n + 1;
        if(m.find(s) != m.end()){
            cout << i + 2 << endl;
            break;
        }
        m[s] = 1;
    }
    return 0;
}