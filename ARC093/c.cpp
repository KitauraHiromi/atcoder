/*
 * Contents   : ARC093 C AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180726
 * Since      : 20180726
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N;
int a[MAX_N+2];
int main(void){
	cin >> N;
	a[0] = 0;
	for(int i=1; i<N+1; i++) cin >> a[i];
	a[N+1] = 0;
	int path = 0;
	for(int i=1; i<N+2; i++) path += abs(a[i] - a[i-1]);
	for(int i=1; i<N+1; i++){
		if((a[i-1] - a[i] > 0) && (a[i+1] - a[i] > 0)) cout << path - 2*abs(min(a[i-1], a[i+1]) - a[i]) << endl;
		else if((a[i-1] - a[i] < 0) && (a[i+1] - a[i] < 0)) cout << path - 2*abs(max(a[i-1], a[i+1]) - a[i]) << endl;
		else cout << path << endl;
	}
	return 0;
}