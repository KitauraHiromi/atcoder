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

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}

signed main(){
	int a, b;
	cin >> n >> a;
	REP(i, n-1){
		cin >> b;
		b = gcd(a, b);
		a = b;
	}
	cout << a << endl;
    return 0;
}