#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
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
	cin >> n;
	vector<int> a, b(n);

	REP(i, n) cin >> b[i];
	reverse(b.begin(), b.begin() + n);
	REP(i, n){
		REP(j, b.size()){
			if(b[j] == b.size() - j){
				a.pb(b[j]);
				b.erase(b.begin() + j);
				break;
			}
		}
	}
	reverse(a.begin(), a.begin()+n);
	if(b.empty()) REP(i, n)  cout << a[i] << endl;
	else cout << -1 << endl;
    return 0;
}