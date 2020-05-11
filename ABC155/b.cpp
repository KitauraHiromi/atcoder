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
ll n;

signed main(){
    cin >> n;
    REP(i, n){
        ll a; cin >> a;
        if(a % 2 == 0){
            if(a % 3 != 0 && a % 5 != 0){
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }
    cout << "APPROVED" << endl;

    return 0;
}