/*
 * Contents   : ARC101 C問題
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180828
 * Since      : 20180828
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
#define INF 10000000000001
typedef long long ll;
ll N, K, x[MAX_N];
int main(void){
	cin >> N >> K;
	for(ll i=0; i<N; i++){
		cin >> x[i];
	}
	ll ret = INF;
	for(ll i=0; i<N-K+1; i++){
		ret = min(ret, min(abs(x[i]), abs(x[i+K-1])) + x[i+K-1] - x[i]);
	}
	cout << ret << endl;
}