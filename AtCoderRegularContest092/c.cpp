/*
 * Contents   : ARC092 C AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180729
 * Since      : 20180729
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define INF 1<<30
typedef pair<int, int> P;
P r[MAX_N], b[MAX_N];
bool rused[MAX_N], bused[MAX_N];
int N;
int main(void){
	int cnt = 0;
	fill(rused, rused+N, false);
	fill(bused, bused+N, false);
	cin >> N;
	for(int i=0; i<N; i++) cin >> r[i].first >> r[i].second;
	for(int i=0; i<N; i++) cin >> b[i].first >> b[i].second;
	sort(r, r+N, [](auto& x, auto& y){
		return x.first > y.first;
	});
	for(int i=0; i<N; i++){
		int jpair = -1;
		int min_d = INF;
		for(int j=0; j<N; j++){
			int dx = b[j].first - r[i].first;
			int dy = b[j].second - r[i].second;
			if(dx > 0 && dy > 0 && !rused[i] && !bused[j]){
				if(min_d > dy){
					jpair = j;
					min_d = dy;
				}
			}
		}
		if(jpair != -1 && min_d != INF){
			rused[i] = true;
			bused[jpair] = true;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}