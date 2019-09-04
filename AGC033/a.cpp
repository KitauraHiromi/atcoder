#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 1001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int h, w;
char a[MAX_N][MAX_N];
vector<P> b[2*MAX_N];
int x[4] = {1, -1, 0, 0}, y[4] = {0, 0, 1, -1};


signed main(){
	cin >> h >> w;
	REP(i, h) REP(j, w){
		cin >> a[i][j];
		if(a[i][j] == '#') b[0].pb(P(i, j));
	}
	REP(i, h+w){
		int tmp = 0;	
		for(P e: b[i]){
			int _i = e.first, _j = e.second;
			REP(j, 4){
				if(_i + x[j] >= 0 && _i + x[j] < h && _j + y[j] >= 0 && _j + y[j] < w){
					if(a[_i+x[j]][_j+y[j]] == '.'){
						b[i+1].pb(P(_i+x[j], _j+y[j]));
						a[_i+x[j]][_j+y[j]] = '#';
						tmp++;
					}
				}
			}
		}
		if(tmp == 0){
			cout << i << endl;
			break;
		}
	}
    return 0;
}