/*
 * Contents   : ABC108 D AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180906
 * Since      : 20180906
 */
#include <bits/stdc++.h>
#define MAX_M 60
using namespace std;
int N, M, L, e[MAX_M][3];
int main(void){
	cin >> L;
	N = floor(log2(L)) + 1;
	M = 0;
	for(int i=1; i<N; i++){
		int m = M;
		e[m][0] = i;
		e[m][1] = i+1;
		e[m][2] = 0;
		M++;
	}
	for(int i=1; i<N; i++){
		int m = M;
		e[m][0] = i;
		e[m][1] = i+1;
		e[m][2] = pow(2, i-1);
		M++;
	}
	for(int i=N-1; i>=1; i--){
		if(L - pow(2, i-1) >= pow(2, N-1)){
			int m = M;
			e[m][0] = i;
			e[m][1] = N;
			e[m][2] = L - pow(2, i-1);
			M++;
			L -= pow(2, i-1);
		}
	}
	cout << N << ' ' << M << endl;;
	for(int m=0; m<M; m++) cout << e[m][0] << ' ' << e[m][1] << ' ' << e[m][2] << endl;
}