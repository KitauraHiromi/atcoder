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
	cin >> n;
	int ret = 0;
	for(int i=1; i<=n; i++){
		if(i % 2 == 0) continue;
		int tmp = 0;
		for(int j=1; j<=n; j++){
			if(i % j == 0) tmp++;
		}
		if(tmp == 8) ret++;
	}
	cout << ret << endl;
    return 0;
}