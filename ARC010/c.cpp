/*
 * Contents   : ARC010 C WA
 * Author     : KitauraHiromi
 * LastUpdate : 20180719
 * Since      : 20180718
 */
#include <bits/stdc++.h>
#define MAX_M 10
#define INF 1<<30
using namespace std;
typedef long long ll;
ll dp[1<<MAX_M][MAX_M+1];
map<char, ll> mp, P;
string str;
ll n, m, Y, Z;
// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
int main(void){
	// initialize
	Fill(dp, -INF);
	dp[0][0] = 0;
	cin >> n >> m >> Y >> Z;
	for(ll i=0; i<m; i++){
		char c;
		ll p;
		cin >> c >> p;
		mp[c] = i + 1;
		P[c] = p;
	}
	cin >> str;
	for(ll i=0; i<n; i++){
		char clr = str[i];
		ll c = mp[clr]; // color by ll
		ll p = P[clr]; // poll of color
		// cout << clr << ' ' << c << ' ' << P[clr] << endl;
		for(ll j=(1<<m)-1; j>=0; j--){
			for(ll k=0; k<=m; k++){
				// 次の色cが一番上の色kと同じ場合
				if(dp[j][k] < 0) continue;
				if(c == k) dp[j|(1<<(c-1))][c] = max(dp[j|(1<<(c-1))][c], dp[j][k]+p+Y);
				// 次の色cが一番上の色kと異なり、全色ボーナスありの場合
				else if(((1<<m)-1)&~j == (1<<(c-1))) dp[j|(1<<(c-1))][c] = max(dp[j|(1<<c)][c], dp[j][k]+p+Z);
				// 次の色cが一番上の色kと異なり、全色ボーナスなしの場合
				else dp[j|(1<<(c-1))][c] = max(dp[j|(1<<(c-1))][c], dp[j][k]+p);
			}
		}
		// for(ll j=0; j<(1<<m)-1; j++){
		// 	for(ll k=0; k<=m; k++){
		// 		cout << dp[j][k] << ' ' ;
		// 	}
		// 	cout << endl;
		// }
	}

	ll ans = 0;
	for(ll j=(1<<m)-1; j>=0; j--){
		for(ll k=0; k<=m; k++){
			ans = max(ans, dp[j][k]);
		}
	}
	cout << ans << endl;
}