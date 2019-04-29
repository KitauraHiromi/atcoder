#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 8
#define INF 1000000001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int	n, l[MAX_N];
int a, b, c;

signed main(){
	cin >> n;
	cin >> a >> b >> c;
	REP(i, n) cin >> l[i];
	int m = pow(4, n), ret = INF;	
	REP(i, m){
		int tmp = i, mp = 0;
		int ta = 0, tb = 0, tc = 0;
		REP(j, n){
			if(tmp%4 == 0){
				if(ta != 0) mp += 10;
				ta += l[j];
			}else if(tmp%4 == 1){
				if(tb != 0) mp += 10;
				tb += l[j];
			}else if(tmp%4 == 2){
				if(tc != 0) mp += 10;
				tc += l[j];
			}
			tmp /= 4;
		}
		if(ta == 0 || tb == 0 || tc == 0) continue;
		mp += abs(a - ta);
		mp += abs(b - tb);
		mp += abs(c - tc);
		ret = min(ret, mp);
	}
	cout << ret << endl;
    return 0;
}