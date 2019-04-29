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
int n, k;

signed main(){
	cin >> n >> k;
	int a[MAX_N], b, t, ret = INF;
	REP(i, n){
		cin >> a[i];
		if(a[i] == 1) b = i;
	}
	// i番目から連続するk個の領域を選んだ時、その左側にある要素数はi個, 右側にある要素数はn-k-i個
	// 選ぶにはi+k<nである必要がある
	for(int i=b; i>b-k; i--){
		int l, r, tmp = 1;
		l = i;
		r = n - k - i;
		if(r < 0) continue;
		tmp += (l%(k-1)==0) ? l / (k - 1) : l / (k - 1) + 1;
		tmp += (r%(k-1)==0) ? r / (k - 1) : r / (k - 1) + 1;
		ret = min(ret, tmp);
	}
	cout << ret << endl;
    return 0;
}