/*
 * Contents   : ABC105 C AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180819
 * Since      : 20180819
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_I 32
typedef long long ll;
typedef pair<ll, ll> P;
ll N;
string s;
P p[MAX_I];
bool rec = false;

int main(void){
	p[0].first = 0; p[0].second = 1;
	ll a = 1;
	for(ll i=1; i<MAX_I; i++){
		a *= -2;
		p[i].first = (i%2==1) ? p[i-1].first + a : p[i-1].first;
		p[i].second = (i%2!=1) ? p[i-1].second + a : p[i-1].second;
		// cout << p[i].first << ' ' << p[i].second << endl;
	}
	cin >> N;
	for(ll i=MAX_I-1; i>=1; i--){
		if(p[i].first <= N && N <= p[i].second){
			if(p[i-1].first <= N && N <= p[i-1].second){
				if(rec) s += '0';
			}else{
				rec |= true;
				s += '1';
				N -= pow(-2, i);
			}
		}
	}
	if(N == 1) s += '1';
	else s += '0';
	cout << s << endl;
}