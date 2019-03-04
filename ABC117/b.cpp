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

signed main(){
    cin >> n;
    ll sum=0, l[MAX_N]={};
    rep(i, 0, n){
        cin >> l[i];
        sum += l[i];
    }
    sort(l, l+n, greater<ll>());
    if(sum > 2*l[0]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}