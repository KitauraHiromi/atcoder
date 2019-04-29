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
string s;

signed main(){
	cin >> s;
	int flag = true;
	if(s[0] != 'A') flag = false;
	
	int cnt = 0;
	for(int i=2; i<s.size()-1; i++){
		if(s[i] == 'C') cnt++;
	}
	if(cnt != 1) flag = false;

	int lower_cnt = 0;
	for(auto c: s){
		if(islower(c)) lower_cnt++;
	}
	if(lower_cnt != s.size() - 2) flag = false;
	 
	if(flag) cout << "AC" << endl;
	else cout << "WA" << endl;
    return 0;
}