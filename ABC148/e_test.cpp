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

signed main(){
    cin >> n;
    ll tmp = 1, ret = 0;
    while(n>1){
        tmp*=n;
        while(tmp % 10 == 0 && tmp > 0){
            tmp /= 10;
            ret++;
        }
        n-=10;
    }
    cout << ret << endl;
    return 0;
}