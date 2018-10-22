#include <bits/stdc++.h>
using namespace std;
vector<int> v(3);

int main(void){
	cin >> v[0] >> v[1] >> v[2];
	int ret = 0;
	do{
		for(auto i: v){
			ret = max(ret, v[0] * 10 + v[1] + v[2]);
			ret = max(ret, v[0] + v[1] * 10 + v[2]);
		}
	}while(next_permutation(v.begin(), v.end()));
	cout << ret << endl;
}