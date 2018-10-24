#include <bits/stdc++.h>
using namespace std;
#define MAX_N 101
#define MAX_M 101
#define rep(i, n) for(int i=0; i<n; i++)
int max_x, min_y, x, y, N, M;
int main(void){
	cin >> N >> M >> max_x >> min_y;
	rep(i, N){
		cin >> x;
		max_x = max(max_x, x);
	}
	rep(i, M){
		cin >> y;
		min_y = min(min_y, y);
	}
	if(max_x < min_y) cout << "No War" << endl;
	else cout << "War" << endl;

	return 0;
}