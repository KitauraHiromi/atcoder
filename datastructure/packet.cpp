#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
#define MAX_M 5001
const int B = 1000;
int N, M, A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];
int nums[MAX_N]; // Aをソートしたもの
vector<int> bucket[MAX_N / B]; // 各パケットをソートしたもの

void solve(){

	cin >> N >> M;
	for(int i=0; i<N; i++) cin >> A[i];
	for(int i=0; i<M; i++) cin >> I[i] >> J[i] >> K[i];

	for(int i=0; i<N; i++){
		bucket[i / B].push_back(A[i]);
		nums[i] = A[i];
	}
	sort(nums, nums + N);
	// B個に満たない最後のパケットをソートしていないが、問題ない
	for(int i=0; i<N / B; i++) sort(bucket[i].begin(), bucket[i].end());

	for(int i=0; i<M; i++){
		// [l, r)のk番目の数を求める
		int l = I[i], r = J[i] + 1, k = K[i];

		int lb = -1, ub = N - 1;
		while(ub - lb > 1){
			int md = (lb + ub) / 2;
			int x = nums[md];
			int tl = l, tr = r, c = 0;

			// パケットをはみ出す部分
			while(tl < tr && tl % B != 0) if (A[tl++] <= x) c++;
			while(tl < tr && tr % B != 0) if (A[--tr] <= x) c++;

			// パケットごと
			while(tl < tr){
				int b = tl / B;
				c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
				tl += B;
			}
			if(c >= k) ub = md;
			else lb = md;
		}
		cout << nums[ub] << endl;
	}
}

int main(void){
	solve();
}