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
string s, t;

signed main(){
	cin >> s >> t;
	bool flag = false;
	REP(i, s.size()){
		if(s.substr(i) + s.substr(0, i) == t) flag = true;
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}