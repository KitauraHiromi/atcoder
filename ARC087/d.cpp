#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 0001
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

bool accessible(int x, vector<int> v){
    bitset<32001> dp;
    int m = 16000, n=v.size();
    dp[m] = true;
    rep(i, 0, n){
            dp = (dp<<v[i]) | (dp>>v[i]);
    }
    return dp[16000+x];
}

signed main(){
    string s; cin >> s;
    int x, y; cin >> x >> y;
    vector<int> fx(1, 0), fy(0, 0);
    int n = s.size();
    int cnt = 0;
    rep(i, 0, n){
        if(s[i] == 'F'){
            if(cnt%2==0) fx[cnt/2]++;
            else fy[cnt/2]++;
        }else if(s[i] == 'T'){
            cnt++;
            if(cnt%2==0) fx.pb(0);
            else fy.pb(0);
        }
    }
    if(cnt==s.size() && (x != 0 || y != 0)){
        cout << "No" << endl;
        return 0;
    }
    fx.erase(fx.begin());

    if(accessible(x, fx))
        if(accessible(y, fy)){
            cout << "Yes" << endl;
            return 0;
        }
    cout << "No" << endl;
    return 0;
}