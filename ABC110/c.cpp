#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
string s, t;
map<char, int> ds, dt;
int main(void){
	cin >> s >> t;
	int n = s.length();

	vector<int> ns(n), nt(n);
	rep(i, n){
		if(ds.find(s[i]) == ds.end()) ds[s[i]] = i;
		ns[i] = ds[s[i]];
	}

	rep(i, n){
		if(dt.find(t[i]) == dt.end()) dt[t[i]] = i;
		nt[i] = dt[t[i]];
	}

	if(ns == nt) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}