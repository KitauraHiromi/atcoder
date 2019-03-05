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
stack<char> st;

signed main(){
    string s; cin >> s;
    int ret = 0;
    FOR(i, 0, s.size()){
        if(st.empty()) st.push(s[i]);
        else if(st.top() != s[i]){
            // 見ている要素とマッチングした場合
            ret += 2;
            st.pop();
        }else{
            // マッチングしなかった場合
            st.push(s[i]);
        }
    }
    cout << ret << endl;
    return 0;
}