#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, m1[10], m2[10][10], m3[10][10][10];
string s;
// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

void keta3(int i, int j, int now){
	m3[i][j][now] = 1;
}

void keta2(int i, int now){
	for(int j=0; j<10; j++){
		if(m2[i][j] == 1) keta3(i, j, now);
		if(j == now){
			m2[i][j] = 1;
		}
	}
}

void keta1(int now){
	for(int i=0; i<10; i++){
		if(m1[i] == 1) keta2(i, now);
		if(i == now){
			m1[now] = 1;
		}
	}
}

signed main(){
	cin >> n >> s;
	Fill(m1, 0);
	Fill(m2, 0);
	Fill(m3, 0);
	for(char c: s){
		int now = c - '0';
		keta1(now);
	}

	ll ret = 0;
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				ret += m3[i][j][k];
			}
		}
	}
	cout << ret << endl;
    return 0;
}