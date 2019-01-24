#include <bits/stdc++.h>
using namespace std;
#define MAX_N 101
int N;
string w[MAX_N];
int main(void){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> w[i];
		for(int j=0; j<i; j++){
			if(w[i] == w[j]){
				cout << "No" << endl;
				return 0;
			}
		}
	}

	for(int i=0; i<N-1; i++){
		if(w[i][w[i].size()-1] != w[i+1][0]){
			cerr << w[i][w[i].size()-1] << ' ' << w[i+1][0] << endl;
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}