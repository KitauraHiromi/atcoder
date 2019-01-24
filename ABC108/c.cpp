#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K;
ll choice(ll k){
	ll ret = 0;
	ret += k;
	ret += 3 * k * (k - 1);
	ret += k * (k - 1) * (k - 2);
	return ret;
}

int main(void){
	cin >> N >> K;
	ll ret = 0;
	ret += choice(N / K);
	if(K % 2 == 0){
		ret += choice(((N / (K / 2)) + 1) / 2);
	}
	cout << ret << endl;
}