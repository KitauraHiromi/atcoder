#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define MAX_H 200
#define MAX_W 100
#define rep(i, n) for(ll i=0; i<n; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int h, w;
string img[MAX_H];

signed main(){
    cin >> h >> w;
    rep(i, h){
        cin >> img[2*i];
        img[2*i+1] = img[2*i];
    }
    rep(i, 2*h){
        cout << img[i] << endl;;
    }
    return 0;
}