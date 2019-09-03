#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define INF 1000000001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, k, h[MAX_N];

signed main(){
	cin >> n >> k;
	REP(i, n) cin >> h[i];
	sort(h, h+n);
	int ret = INF;
	REP(i, n-k+1){
		ret = min(ret, h[i+k-1] - h[i]);
	}
	cout << ret << endl;
    return 0;
}