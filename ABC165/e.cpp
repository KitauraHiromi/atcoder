#include <bits/stdc++.h>
#define MAX_N 200001
#define mod 1000000007
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, m;

signed main(){
    cin >> n >> m;
    REP(i, (m+1)/2){
        cout << i + 1 << " " << ((m % 2 == 0) ? (m - i) : (m - i + 1)) << endl;
    }

    REP(i, m/2){
        cout << ((m % 2 == 0) ? (m + i + 1) : (m + i + 2)) << " " << 2 * m - i + 1 << endl;
    }

    return 0;
}