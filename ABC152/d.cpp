#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 200001
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, c[10][10];

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

signed main(){
    cin >> n;
    Fill(c, 0);
    for(ll i=1; i<=n; i++){
        ll b = i % 10;
        ll t = i;
        while(t >= 10){
            t /= 10;
        }
        // assert(t > 0);
        c[t][b]++;
    }
    ll ret = 0;
    REP(i, 10) REP(j, 10) ret += c[i][j] * c[j][i];
    cout << ret << endl;
    return 0;
}