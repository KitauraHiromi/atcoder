#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 50
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, a[MAX_N];
vector<P> v;

signed main(){
    cin >> n;
    ll h, l, ih, il;
    cin >> a[0];
    h = l = a[0]; ih = il = 0;
    rep(i, 1, n){
        cin >> a[i];
        if(h < a[i]){
            h = a[i];
            ih = i;
        }
        if(l > a[i]){
            l = a[i];
            il = i;
        }
    }
    if(h + l >= 0) {
        rep(i, 0, n){
            if(i != ih){
                a[i] += h;
                v.pb(P(ih, i));
            }
        }
        rep(i, 0, n-1){
            if(a[i+1] < a[i]){
                a[i+1] += a[i];
                v.pb(P(i, i+1));
            }
        }
    }else{
        rer(i, n, 0){
            if(i != il){
                a[i] += l;
                v.pb(P(il, i));
            }
        }
        rer(i, n-1, 0){
            if(a[i+1] < a[i]){
                a[i] += a[i+1];
                v.pb(P(i+1, i));
            }
        }
    }
    cout << v.size() << endl;
    for(P e: v){
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }
    // rep(i, 0, n) cout << a[i] << " ";
    // cout << endl;

    return 0;
}