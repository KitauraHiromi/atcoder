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
P ab[MAX_N];

signed main(){
    cin >> n;
    rep(i, 0, n) cin >> ab[i].first >> ab[i].second;
    sort(ab, ab+n, [](P x, P y)->bool{
        return x.first + x.second > y.first + y.second;
    });
    ll ha=0, hb=0;
    rep(i, 0, n){
        if(i%2==0) ha += ab[i].first;
        else hb += ab[i].second;
    }
    cout << ha - hb << endl;
    return 0;
}