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
ll n, x;
vector<ll> divisor_x;

signed main(){
    cin >> x;
    for(ll i=1; i*i<=x; i++){
        if(x % i == 0) divisor_x.pb(i);
    }
    divisor_x.pb(x);

    for(ll a=1; a <= 1000; a++){
        // for(ll d: divisor_x){
        //     ll b = a - d;
        for(ll b=0; b<=1000; b++){
            if(a*a*a*a*a - b*b*b*b*b == x){
                cout << a << ' ' << b << endl;
                return 0;
            }
            if(a*a*a*a*a + b*b*b*b*b == x){
                cout << a << ' ' << -b << endl;
                return 0;
            }
        }
    }
    cout << "fail" << endl;
    return 0;
}