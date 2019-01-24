/*
 * Contents   : ABC106 C AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180819
 * Since      : 20180819
 */
 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K;
string S;
int main(void){
	cin >> S >> K;
	for(int i=0; i<S.size(); i++){
		if(S[i] != '1'){
			cout << S[i] << endl;
			return 0;
		}else if(S[i] == '1' && i == K-1){
			cout << '1' << endl;
			return 0;
		}else if(i == S.size()-1){
			cout << '1' << endl;
			return 0;
		}
	}
}