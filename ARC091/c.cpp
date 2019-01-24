/*
 * Contents   : ARC091 C AC 
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180731
 * Since      : 20180731
 */
#include <bits/stdc++.h>
using namespace std;
long long N, M;
int main(void){
	cin >> N >> M;
	if(N < M) swap(N, M); // N > M
	if(M == 1){
		if(N > 2) cout << N - 2 << endl;
		else if(N == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else cout << (N - 2) * (M - 2) << endl;
	return 0;
}