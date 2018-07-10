/*
 * Contents   : ARC008 C問題 AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180710
 * Since      : 20180710
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_V 1000
#define INF 1<<30
double d[MAX_V][MAX_V];
double x[MAX_V], y[MAX_V], t[MAX_V], r[MAX_V];
int N;

int main(void){
	cin >> N;
	for(int i=0; i<N; i++) cin >> x[i] >> y[i] >> t[i] >> r[i];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
				double dx = x[i] - x[j];
				double dy = y[i] - y[j];
				d[i][j] = sqrt(dx*dx + dy*dy) / min(t[i], r[j]);
		}
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	double ret = 0;
	sort(d[0], d[0]+N);
	for(int i=1; i<N; i++){
		ret = max(ret, d[0][i]+(N-1-i));
	}
	printf("%.6f\n", ret);
}