/*
 * Contents   : ARC012 C問題 WA
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180724
 * Since      : 20180723
 */
#include <bits/stdc++.h>
#define N 19
using namespace std;
char goban[N][N];
int main(void){
	for(int i=0; i<N; i++){
		cin >> goban[i];
	}
	int cnt_blk = 0;
	int cnt_wht = 0;
	// 個数による検討
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(goban[i][j] == 'o') cnt_blk++;
			else if(goban[i][j] == 'x') cnt_wht++;
		}
	}

	// 連続数による検討
	int seq_blk = 1;
	int seq_wht = 1;
	// 縦
	for(int i=0; i<N; i++){
		int tmpb = 1;
		int tmpw = 1;
		for(int j=1; j<N; j++){
			if(goban[i][j-1] == 'o' && goban[i][j] == 'o'){
				tmpb++;
			}else if(goban[i][j-1] == 'x' && goban[i][j] == 'x'){
				tmpw++;
			}
			if((goban[i][j-1] == 'o' && goban[i][j] != 'o') || j == N-1){
				seq_blk = max(seq_blk, tmpb);
			}if((goban[i][j-1] == 'x' && goban[i][j] != 'x') || j == N-1){
				seq_wht = max(seq_wht, tmpw);
			}
		}
	}
	// 横
	for(int j=0; j<N; j++){
		int tmpb = 1;
		int tmpw = 1;
		for(int i=1; i<N; i++){
			if(goban[i-1][j] == 'o' && goban[i][j] == 'o'){
				tmpb++;
			}else if(goban[i-1][j] == 'x' && goban[i][j] == 'x'){
				tmpw++;
			}
			if((goban[i-1][j] == 'o' && goban[i][j] != 'o') || i == N-1){
				seq_blk = max(seq_blk, tmpb);
			}if((goban[i-1][j] == 'x' && goban[i][j] != 'x') || i == N-1){
				seq_wht = max(seq_wht, tmpw);
			}
		}
	}
	// 斜め
	for(int k=1; k<2*N; k++){
		int tmpb = 1;
		int tmpw = 1;
		for(int l=1; l<N; l++){
			if(goban[l-1][k-l+1] == 'o' && goban[l][k-l] == 'o'){
				tmpb++;
			}else if(goban[l-1][k-l+1] == 'x' && goban[l][k-l] == 'x'){
				tmpw++;
			}
			if((goban[l-1][k-l+1] == 'o' && goban[l][k-l] != 'o') || l == N-1 || k-l == 0){
				seq_blk = max(seq_blk, tmpb);
			}if((goban[l-1][k-l+1] == 'x' && goban[l][k-l] != 'x') || l == N-1 || k-l == 0){
				seq_wht = max(seq_wht, tmpw);
			}
		}
	}

	for(int k=-N+1; k<N; k++){
		int tmpb = 1;
		int tmpw = 1;
		for(int l=0; l<N; l++){
			if(goban[l-1][l+k-1] == 'o' && goban[l][l+k] == 'o'){
				tmpb++;
			}else if(goban[l-1][l+k-1] == 'x' && goban[l][l+k] == 'x'){
				tmpw++;
			}
			if((goban[l-1][l+k-1] == 'o' && goban[l][l+k] != 'o') || l == N-1 || l+k == 0){
				seq_blk = max(seq_blk, tmpb);
			}if((goban[l-1][l+k-1] == 'x' && goban[l][l+k] != 'x') || l == N-1 || l+k == 0){
				seq_wht = max(seq_wht, tmpw);
			}
		}
	}

	// cout << seq_blk << ' ' << seq_wht << endl;

	if(cnt_blk - cnt_wht != 1 && cnt_wht != cnt_blk) cout << "NO" << endl;
	else if(seq_blk > 9 || seq_wht > 9) cout << "NO" << endl;
	else if(seq_blk >= 5 && seq_wht >= 5) cout << "NO" << endl;
	else if(seq_blk >= 5 && cnt_blk == cnt_wht) cout << "NO" << endl;
	else if(seq_wht >= 5 && cnt_blk > cnt_wht) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}