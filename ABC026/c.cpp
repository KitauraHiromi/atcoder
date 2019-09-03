#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define INF 1000000000
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, b[MAX_N], m[20];

signed main(){
	cin >> n;
	for(ll i=1; i<n; i++){
		cin >> b[i];
	}

	for(ll i=0; i<n; i++) m[i] = 0;
	// confirmed person
	bool p[20];
	do{
		for(ll i=0; i<n; i++) p[i] = true;
		// 給料が確定している人のみを部下に持つ人を抽出
		for(ll i=1; i<n; i++){
			if(m[i] == 0) p[b[i]-1] = false;
		}
		// for(ll i=0; i<n; i++){ if(p[i]) cout << i << "is confirmed" << endl;}
		// 新しく確定する人の直属の部下を抽出, 給料を確定する
		for(ll i=0; i<n; i++){
			if(p[i] && m[i] == 0){
				ll mmax = 0;
				ll mmin = INF;
				for(ll j=1; j<n; j++){
					if(b[j]-1 == i){
						mmax = max(mmax, m[j]);
						mmin = min(mmin, m[j]);
					}
				}
				if(mmax != 0 && mmin != INF) m[i] = mmax + mmin + 1;
				else m[i] = 1;
			}
		}
		// cout << m[0] << endl;
	}while(m[0] == 0);
	cout << m[0] << endl;
    return 0;
}