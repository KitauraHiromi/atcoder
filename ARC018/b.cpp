/*
 * Contents   : ARC018 B問題 AC
 * Author     : KitauraHiromi
 * LastUpdate : 20180725
 * Since      : 20180724
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
typedef long long ll;
ll x[MAX_N], y[MAX_N];
int N;
ll cnt;
int main(void){
	cin >> N;
	cnt = 0;
	for(int i=0; i<N; i++) cin >> x[i] >> y[i];
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			for(int k=j+1; k<N; k++){
				ll dx1 = x[i] - x[k]; ll dx2 = x[j] - x[k];
				ll dy1 = y[i] - y[k]; ll dy2 = y[j] - y[k];
				ll S = dx1 * dy2 - dx2 * dy1;
				if(S == 0) continue;
				if(S % 2 == 0) cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}