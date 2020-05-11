#include <bits/stdc++.h>
#define MAX_N 200002
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
ll n, k, a[MAX_N];
ll used[MAX_N];

signed main(){
    cin >> n >> k;
    FOR(i, 1, n+1){
        cin >> a[i];
    }
    ll s = 1, cnt = 0;
    REP(i, n+1) used[i] = 0;
    used[1] = 1;
    bool once = true;

    ll i = 0;
    while(i < k){
        s = a[s];
        i++;
        if(used[s] == 1) cnt++;
        else if(used[s] == 2 && once){
            k = (k - i) % cnt + i;
            once = false;
        }
        used[s]++;
    }
    
    cout << s << endl;
    return 0;
}