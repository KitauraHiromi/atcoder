#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_M 100001
#define MAX_N 100001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, m;
int p[MAX_M], y[MAX_M];
vector<int> yd[MAX_N];

signed main(){
	cin >> n >> m;
	REP(i, m){
		cin >> p[i] >> y[i];
		yd[p[i]].pb(y[i]);
	}
	REP(i, n){
		sort(yd[i+1].begin(), yd[i+1].end());
	}
	REP(i, m){
		cout << setfill('0') << setw(6) << right << p[i];
		cout << setfill('0') << setw(6) << right << int(lower_bound(yd[p[i]].begin(), yd[p[i]].end(), y[i]) - yd[p[i]].begin()) + 1;
		cout << endl;
	}
    return 0;
}