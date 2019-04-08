#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, x, a[MAX_N];
signed main(){
    cin >> n >> x;
    REP(i, n) cin >> a[i];
    ll ret = 0, pre = 0;
    REP(i, n){
        if(pre + a[i] >= x){
            ret += pre + a[i] - x;
            pre = x - pre;
            // cout << pre << endl;
        }else{
            pre = a[i];
            // cout << pre << endl;

        }
    }
    cout << ret << endl;
    return 0;
}