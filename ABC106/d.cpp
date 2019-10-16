#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 501
#define MAX_M 200001
#define MAX_Q 100001
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, m, q, a[MAX_N][MAX_N], x[MAX_N][MAX_N];
P lr[MAX_M], pq[MAX_Q];

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}

signed main(){
	cin >> n >> m >> q;
	REP(i, m){ cin >> lr[i].first >> lr[i].second; lr[i].first--; lr[i].second--; }
	REP(i, q){ cin >> pq[i].first >> pq[i].second; pq[i].first--; pq[i].second--; }

	Fill(x, 0); Fill(a, 0);
	REP(i, m) a[lr[i].first][lr[i].second]++;
	REP(i, n) REP(j, n) x[i][j] = (j >= 1) ? x[i][j-1] + a[i][j] : a[i][j];

	REP(i, q){
		ll ret = 0;
		FOR(j, pq[i].first, pq[i].second+1){
			// cout << x[j][pq[i].second] << " " << x[j][pq[i].first] << endl;	
			if(pq[i].first - 1 >= 0) ret += x[j][pq[i].second] - x[j][pq[i].first - 1];
			else ret += x[j][pq[i].second];
		}
		cout << ret << endl;
	}
    return 0;
}