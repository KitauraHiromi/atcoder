#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
ll n, sx, sy;
char a[MAX_N][MAX_N];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};


bool dfs(ll x, ll y){
	if(a[x][y] == 'g') return true;
	else if(a[x][y] == '#') return false;
	else if(a[x][y] == '.'){
		bool ret = false;
		ret |= dfs(x+dx[0], x+dy[0]); 
		ret |= dfs(x+dx[1], x+dy[1]);
		ret |= dfs(x+dx[2], x+dy[2]);
		ret |= dfs(x+dx[3], x+dy[3]);
		return ret;
	}
	return false;
}	

signed main(){
	cin >> n;
	REP(i, n) REP(j, n){ 
		cin >> a[i][j];
		if(a[i][j] == 's'){ sx = i; sy = j;}
	}
	if(dfs(sx, sy)) cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}