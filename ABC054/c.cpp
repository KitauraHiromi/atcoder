// one stroke path
#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 9
#define MAX_M 100
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, m;
int e[MAX_M][2];
bool not_visited[MAX_N];

int dfs(int v){
	FOR(i, 1, n+1){
		if(not_visited[i]) break;
		if(i == n) return 1;
	}

	int ret = 0;
	REP(i, m){
		REP(j, 2){
			if(e[i][j] == v && not_visited[e[i][1-j]]){
				not_visited[e[i][1-j]] = false;
				ret += dfs(e[i][1-j]);
				not_visited[e[i][1-j]] = true;
			}
		}
	}
	return ret;
}

signed main(){
	cin >> n >> m;
	REP(i, m) cin >> e[i][0] >> e[i][1];
	REP(i, n+1) not_visited[i] = true;
	not_visited[1] = false;
	int ret = dfs(1);
	cout << ret << endl;

    return 0;
}