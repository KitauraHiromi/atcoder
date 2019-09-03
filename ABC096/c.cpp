#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_H 51
#define MAX_W 51
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int h, w;
bool s[MAX_H][MAX_W];
signed main(){
	cin >> h >> w;
	REP(i, h){
		REP(j, w){
			char c; cin >> c;
			if(c == '#') s[i][j] = true;
			else s[i][j] = false;
		}
	}
	bool flag = true;
	REP(i, h){
		REP(j, w){
			bool paintable = false;
			if(!s[i][j]) continue;
			if(i > 0) paintable |= s[i-1][j];
			if(i < h-1) paintable |= s[i+1][j];
			if(j > 0) paintable |= s[i][j-1];
			if(j < w-1) paintable |= s[i][j+1];
			flag &= paintable;
		}
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}