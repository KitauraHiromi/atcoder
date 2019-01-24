/*
 * Contents   : ARC 009 AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180710
 * Since      : 20180710
 */
#include <bits/stdc++.h>
#define mod 1777777777
#define MAX_N 777777777777777777
#define MAX_K 777777
typedef long long ll;
using namespace std;
ll N, K;

inline ll inverse(ll  a, ll  m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll  t = a / b;
        swap(a -= t * b, b);
        swap(u -= t * v, v);
    }
    return (u % m + m) % m;
}

ll montmort[MAX_K];
void init_montmort(ll n){
	montmort[0] = 0;
	montmort[1] = 1;
	for(ll i=2; i<=n; i++){
		montmort[i] = i * (montmort[i-1] + montmort[i-2]) % mod;
	}
}

ll large_combination(ll n, ll r){
    ll ans = 1;
    while(r){
        ll N = n % mod;
        ll R = r % mod;
        if(N < R){
            return 0;
        }
        for(ll i = 0; i < R; i++){
            ans = ans * (N - i) % mod;
        }
        ll mul = 1;
        for(ll i = 0; i < R;i++){
            mul = mul * (i + 1) % mod;
        }
        ans = ans * inverse(mul, mod) % mod;
        n /= mod;
        r /= mod;
    }
    return ans;
}

int main(void){
	cin >> N >> K;
	init_montmort(K);
	cout << large_combination(N, K) % mod * montmort[K-1] % mod << endl;
}
