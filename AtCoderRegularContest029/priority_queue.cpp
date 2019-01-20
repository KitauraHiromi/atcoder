#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#include <queue>
#define MAX_N 100001
#define rep(i, n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n;

signed main(){
    priority_queue<ll> q;
    priority_queue<ll, vector<ll>, greater<ll>> r;
    priority_queue<P, vector<P>, greater<P>> l;
    cin >> n;
    rep(i, n){
        ll x;
        cin >> x;
        q.push(x);
        r.push(x);
    }
    rep(i, n){
        cout << q.top() << endl;
        q.pop();
    }
    rep(i, n){
        cout << r.top() << endl;
        r.pop();
    }
    rep(i, n){
        ll x, y;
        cin >> x >> y;
        l.push(P(x, y));
    }
    rep(i, n){
        P top = l.top();
        cout << top.first << " " << top.second << endl;
        l.pop();
    }
    return 0;
}