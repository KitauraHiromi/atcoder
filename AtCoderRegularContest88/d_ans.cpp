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
string s;
signed main(){
    cin >> s;
    int n = s.size();
    int ret = n;
    rep(i, n-1){
        if(s[i+1] != s[i]){
            int k = max(i+1, n-i-1);
            ret = min(ret, k);
        }
    }
    cout << ret << endl;
    return 0;
}