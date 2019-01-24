/*
 * Contents   : ARC089C AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180829
 * Since      : 20180829
 */
#include <bits/stdc++.h>
using namespace std;
int N;
int main(void){
	cin >> N;
	int pret, prex, prey;
	pret = prex = prey = 0;

	for(int i=0; i<N; i++){
		int x, y, t;
		cin >> t >> x >> y;
		int difft = abs(t - pret);
		int diffx = abs(x - prex);
		int diffy = abs(y - prey);
		if(diffx + diffy > difft || (diffx + diffy) % 2 != difft % 2){
			cout << "No" << endl;
			return 0;
		}
		pret = t; prex = x; prey = y;
	}
	cout << "Yes" << endl;
	return 0;
}