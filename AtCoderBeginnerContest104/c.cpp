/*
 * Contents   : ABC104 C AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180819
 * Since      : 20180819
 */
 #include <bits/stdc++.h>
using namespace std;
#define MAX_D 11
#define INF 1<<30
typedef long long ll;
ll D, G, p[MAX_D], c[MAX_D];

int  main(void){
	cin >> D >> G;

	for(ll i=0; i<D; i++){
		cin >> p[i] >> c[i];
	}

	ll res = INF;
	for(ll i=0; i<(1<<D); i++){
		ll g = 0; ll n = 0;
		for(ll j=0; j<D; j++){
			if(i>>j&1){
				g += p[j] * (j+1) * 100 + c[j];
				n += p[j];
			}
		}

		if(G <= g) res = min(res, n);
		else{
			for(ll j=0; j<D; j++){
				if(!(i>>j&1) && G > g && G <= g + (j+1) * 100 * p[j]){
					res = min(res, n + ll(ceil(double(G - g) / (j+1) / 100)));
				}
			}
		}
	}
	cout << res << endl;
}