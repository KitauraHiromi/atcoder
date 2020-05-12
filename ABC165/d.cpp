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
ll a, b, n;

signed main(){
    cin >> a >> b >> n;
    if(n >= b){
        double u = (double)(b-1) / b;
        cout << floor(a * u) << endl;
    }else{
        double u = (double)n / b;
        cout << floor(a * u) << endl;
    }
    return 0;
}