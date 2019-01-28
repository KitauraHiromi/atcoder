#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define rer(i, a, b) for(ll i=a-1; i>=b; i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int n;

signed main(){
    int a, b;
    cin >> n >> a >> b;
    cout << min(a, b) << " " << max(a + b - n, 0) << endl;
    return 0;
}