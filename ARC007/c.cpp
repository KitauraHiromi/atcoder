// すべてのテレビをつけた瞬間から、最後のテレビが一巡するまでの穴を埋められれば良い
// 9通りのテレビのつけ方をすべて試す。2^9通りの全探索
#include <bits/stdc++.h>
#define MAX_N 10
using namespace std;
int N;
string tmp;
bool pat[MAX_N];
int main(void){
	cin >> tmp;
	N = tmp.size();
	for(int i=0; i<N; i++){
		if(tmp[i] == 'o') pat[i] = true;
		else if(tmp[i] == 'x') pat[i] = false;
	}
	int ans = N;
	for(int i=1; i<1<<N; i++){
		bool bits[N];
		fill(bits, bits+N, false);
		int tmp_ans = 0;
		for(int j=0; j<N; j++){
			if(i>>j&1){
				// j分ずれた期間との和集合
				tmp_ans++;
				for(int k=0; k<N; k++){
					if(k+j<N) bits[k] |= pat[k+j];
					else bits[k] |= pat[k+j-N];
				}
			}
		}
		bool flag = true;
		for(int l=0; l<N; l++) flag &= bits[l]; 
		if(flag) ans = min(ans, tmp_ans);
	}
	cout << ans << endl;
}