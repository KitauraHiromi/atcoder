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
pair<double, P> rxy[MAX_N];

double deg(ll x, ll y){
    if(x == 0 && y == 0) return 0;
    return atan2(y, x) * 180 / M_PI;
}

signed main(){
    cin >> n;
    REP(i, n) cin >> rxy[i].second.first >> rxy[i].second.second;
    REP(i, n){
        ll x, y;
        x = rxy[i].second.first; y = rxy[i].second.second;
        rxy[i].first = deg(x, y);
        // cout << x << " " << y << " " << rxy[i].first << endl;
    }
    sort(rxy, rxy+n);
    // REP(i, n) cout << rxy[i].first << " " << rxy[i].second.first << " " << rxy[i].second.first << endl;
    P ret_xy = P(0, 0);
    double ret = 0;
    REP(i, n){
        REP(j, n){
            REP(k, n){
                if(i <= k && k <= j){
                    ret_xy.first += rxy[k].second.first;
                    ret_xy.second += rxy[k].second.second;
                }
            }
            ret = max(ret, sqrt(ret_xy.first*ret_xy.first + ret_xy.second*ret_xy.second));
            ret_xy = P(0, 0);

            REP(k, n){
                if(k <= i || j <= k){
                    ret_xy.first += rxy[k].second.first;
                    ret_xy.second += rxy[k].second.second;
                }
            }
            ret = max(ret, sqrt(ret_xy.first*ret_xy.first + ret_xy.second*ret_xy.second));
            ret_xy = P(0, 0);
        }
    }
    cout << setprecision(20) << ret << endl;
    return 0;
}