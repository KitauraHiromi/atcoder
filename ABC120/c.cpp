#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n;

signed main(){
    string s; cin >> s;
    char c[MAX_N];
    c[0] = s[0];
    int k = 0, ret = 0;
    FOR(i, 1, s.size()){
        if(s[i] == c[k]){
            // 見ている要素とマッチングした場合
            ret += 2;
            k = max(k-1, 0);
        }else{
            // マッチングしなかった場合
            k++;
            c[k] = s[i];
        }
    }
    REP(i, s.size()) cout << c[i] << " ";
    cout << endl;
    cout << ret << endl;
    return 0;
}