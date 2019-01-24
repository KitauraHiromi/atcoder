#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#include <algorithm>
#define MAX_N 100001
#define rep(i, n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n;

signed main(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    cout << a[0] * a[1] / 2.0 << endl;

    return 0;
}