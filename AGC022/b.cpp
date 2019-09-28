#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n;

signed main(){
	cin >> n;
	if(n == 3) cout << "2 5 63" << endl;
	else if(n == 4) cout << "2 5 20 63" << endl;
	else if(n == 5) cout << "2 5 20 30 63" << endl;
	else{
		vector<double> v;
		REP(i, n/4+1){
			if(v.size() < n) v.pb(6 * i + 2);
			if(v.size() < n) v.pb(6 * i + 3);
			if(v.size() < n) v.pb(6 * i + 4);
			if(v.size() < n) v.pb(6 * i + 6);
		}
		int s = accumulate(ALL(v), 0) % 6;
		if(s == 0); 
		else if(s == 2) v[4] = 6 * (v.size() / 4 + 1);
		else if(s == 3) v[5] = 6 * (v.size() / 4 + 1);
		else if(s == 5) v[n-1]++;
		for(auto c: v) cout << c << " ";
		cout << endl;
		// bool over = false;
		// for(auto c: v) over |= (c > 30000);
		// if(!over) cout << "success" << endl;
		// else cout << "fali" << endl;
	}
    return 0;
}