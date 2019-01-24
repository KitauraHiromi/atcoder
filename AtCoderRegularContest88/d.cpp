#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#include <string>
#define MAX_N 100001
#define rep(i, n) for(ll i=0; i<n; i++)
#define repq(i, m, n) for(ll i=m; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

bool check0(string s, int n, int l){
    rep(i, n-l+1){
        if(s[i] == '1'){
            rep(j, l){
                // rep(m, i) cout << s[m]; cout << " ";
                s[i+j] = (s[i+j]=='1') ? '0' : '1';
            }
        }
    }
    rep(i, n) if(s[i] == '1') return false;
    return true;
}
bool check1(string s, int n, int l){
    rep(i, n-l+1){
        if(s[i] == '0'){
            rep(j, l){
                // rep(m, i) cout << s[m]; cout << " ";
                s[i+j] = (s[i+j]=='1') ? '0' : '1';
            }
        }
    }
    rep(i, n) if(s[i] == '0') return false;
    return true;
}

signed main(){
    string s; cin >> s;
    int n = s.size();
    vector<int> v(n, 0);
    // if(s[0] == '1') v[0] = 1;
    repq(i, 1, n){
        // cout << i+1 << " " << v[i-1] + 1 << endl;
        if(check0(s, i+1, v[i-1]+1) || check1(s, i+1, v[i-1]+1)) v[i] = v[i-1] + 1;
        else v[i] = v[i-1];
    }
    // rep(i, n) cout << v[i] << " ";
    // cout << endl;
    cout << v[n-1] << endl;
    // if(check1(s, n, n)) cout << "ok" << endl;
    // else cout << "ng" << endl;
    return 0;
}