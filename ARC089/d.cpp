/*
 * Contents   : ARC089 D AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180905
 * Since      : 20180905
 */
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << endl; 
#define MAX_K 1001
#define rep(i, n) for(int i=0; i<n; i++)
int N, K;
int s[3*MAX_K][3*MAX_K], a[2][MAX_K][MAX_K];
signed main(void){
	cin >> N >> K;
	for(int i=0; i<N; i++){
		int x, y;
		char c;
		cin >> x >> y >> c;
		if(c == 'B') x += K;
		x %= 2*K;
		y %= 2*K;
		s[x][y]++;
		s[x + K][y]--;
		s[x][y + K]--;
		s[x + K][y + K]++;
	}

	rep(i, 3*K) rep(j, 3*K) s[i][j+1] += s[i][j];
	rep(i, 3*K) rep(j, 3*K) s[i+1][j] += s[i][j];
	rep(i, 3*K) rep(j, 3*K){
		int k = (i / K + j / K) % 2;
		a[k][i%K][j%K] += s[i][j];
	} 
	// rep(k, 2) rep(i, K){
	// 	rep(j, K) cerr << a[k][i][j] << ' ';
	// 	cerr << endl;
	// }
	int ret = 0;
	rep(k, 2) rep(i, K) rep(j, K) ret = max(ret, a[k][i][j]);
	cout << ret << endl;
}