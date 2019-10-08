#include <bits/stdc++.h>

#define MAX_N 100001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n;

signed main(){

	int n, k, a[1000];
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> a[i];

	auto check = [&](ll v){
		ll ret = 0;
		for(int i=0; i<n; i++){
			ll all = 0;
			for(int j=i; j<n; j++){
				all += a[j];
				if((all & v) >= v) ret++;
			}
		}
		return ret >= k;
	};

	ll bit = 0;
	for(ll i=50; i>=0; i--){
		if(check(bit | (1LL << i))) bit |= 1LL << i;
	}
	cout << bit << endl;
    return 0;
}