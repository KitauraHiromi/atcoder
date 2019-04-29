#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n;

int dfs(string s){
	if(atoi(s.c_str()) > n || s.size() > 9) return 0;
	if(s.find('7') != std::string::npos && s.find('5') != std::string::npos && s.find('3') != std::string::npos)
		return dfs(s + '7') + dfs(s + '5') + dfs(s + '3') + 1;
	else return dfs(s + '7') + dfs(s + '5') + dfs(s + '3');
}

signed main(){
	cin >> n;
	cout << dfs(string("")) << endl;
    return 0;
}