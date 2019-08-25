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

signed main(){
	int m, d, ret;
	ret = 0;
	cin >> m >> d;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=d; j++){
			int d1 = j%10;
			int d10 = j/10;
			if(d1 >= 2 && d10 >= 2 && d1*d10 == i) ret++;
		}
	}
	cout << ret << endl;
    return 0;
}