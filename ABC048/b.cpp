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
ll a, b, x;
signed main(){
    // [a, b] = [0, b] - [0, a)
    cin >> a >> b >> x;
    cout << b/x - a/x + ((a%x==0)? 1 : 0) << endl;
    return 0;
}