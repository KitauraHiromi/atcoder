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
string s;
ll n;
ll rgb[3];

signed main(){
    cin >> n >> s;

    // set rgb
    rgb[0] = rgb[1] = rgb[2] = 0;

    for(ll i=0; i<n; i++){
        if(s[i]=='R') rgb[0]++;
        if(s[i]=='G') rgb[1]++;
        if(s[i]=='B') rgb[2]++;
    }

    ll ret = rgb[0] * rgb[1] * rgb[2];

    for(ll j=1; j<=n-2; j++){
        for(ll i=0; i<j; i++){
            ll k = j + (j - i);
            if(k < n){
                if(s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) ret--;
            }
        }
    }

    cout << ret << endl;

    return 0;
}