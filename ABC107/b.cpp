#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_H 100
#define MAX_W 100
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int h, w;
char a[MAX_H][MAX_W];
bool b[MAX_H + MAX_W];
signed main(){
	cin >> h >> w;
	REP(i, h) REP(j, w) cin >> a[i][j];
	REP(i, h){
		bool eliminate = true;
		REP(j, w){
			if(a[i][j] == '#') eliminate = false;
		} 
		b[i] = eliminate;
	}
	REP(j, w){
		bool eliminate = true;
		REP(i, h){
			if(a[i][j] == '#') eliminate = false;
		} 
		b[h + j] = eliminate;
	}

	REP(i, h){
		REP(j, w){
			if(b[i] || b[h + j]) continue;
			else  cout << a[i][j];
		}
		cout << endl;
	}
    return 0;
}