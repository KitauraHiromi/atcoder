/*
 * Contents   : ARC 006 C問題 AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180705
 * Since      : 20180705
 */
// int ret 段ボールの山の数
// 新しい荷物がどの段ボールの山にも乗らない場合、+1
// 新しい荷物が一つの山における場合、そこに置き山の頂上の重さを更新する
// 新しい荷物が二つ以上の山における場合、最も軽い段ボールに乗せれば必ず良い更新になる
// 状態：各山の一番上の段ボールの重さ
#include <bits/stdc++.h>
#define MAX_N 50
#define INF 1<<30;
using namespace std;
int N;
int pile[MAX_N];
int main(void){
	cin >> N;
	int ret = 0;
	int h; // 新しい荷物の重さ
	for(int i=0; i<N; i++){
		cin >> h;
		// h以上の重さで最小の山頂を見つける
		int tmp = INF;
		int tmp_j = MAX_N;
		for(int j=0; j<ret; j++){
			if(pile[j] >= h){
				if(pile[j] < tmp){
					tmp = pile[j];
					tmp_j = j;
				}
			}
		}
		// もしあれば、そこに乗せる
		if(tmp_j < MAX_N) pile[tmp_j] = h;
		// なければ、新しい山を作る
		else{
			pile[ret] = h;
			ret++;
		}
	}
	cout << ret << endl;
}