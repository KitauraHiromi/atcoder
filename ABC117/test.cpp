#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 58;
int N;
int64 A[100000], K;
int64 dp[45][2];
int prop[45];

int64 rec(int idx, bool free) {
  if(idx < 0) return 0;
  if(~dp[idx][free]) return dp[idx][free];
  int64 ret = -INF;
  for(int i = 0; i <= (free ? 1 : ((K >> idx) & 1)); i++) {
    ret = max(ret, rec(idx - 1, free | (((K >> idx) & 1) != i)) + 1LL * (i == 0 ? prop[idx] : N - prop[idx]) * (1LL << idx));
  }
  return dp[idx][free] = ret;
}

int main() {
  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < 45; i++) {
    for(int j = 0; j < N; j++) {
      if((A[j] >> i) & 1) prop[i]++;
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << rec(44, false) << endl;
  for(int i=0; i<45; i++){
  	cout << dp[i][0] << " " << dp[i][1] << endl;
  }
}
