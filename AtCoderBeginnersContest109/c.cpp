#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
#define INF 1000000000
int N, X, x[MAX_N];
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a % b);
}

int main(void){
	cin >> N >> X;
	for(int i=0; i<N; i++) cin >> x[i];
	for(int i=0; i<N; i++) x[i] = abs(X - x[i]);
	int min_x = INF;
	for(int i=0; i<N; i++) min_x = min(min_x, x[i]);
	int min_gcd = INF;
	for(int i=0; i<N; i++) min_gcd = min(min_gcd, gcd(min_x, x[i]));
	cout << min_gcd << endl;
	return 0;
}