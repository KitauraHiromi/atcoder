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
ll rgbi[MAX_N][3], rgbk[MAX_N][3];

signed main(){
    cin >> n >> s;

    // set rgbi and rgbk
    rgbi[1][0] = rgbi[1][1] = rgbi[1][2] = 0;
    rgbk[1][0] = rgbk[1][1] = rgbk[1][2] = 0;
    // j = 1 (1 <= j <= n-2)
    if(s[0]=='R') rgbi[1][0]++;
    if(s[0]=='G') rgbi[1][1]++;
    if(s[0]=='B') rgbi[1][2]++;
    for(ll k=2; k<n; k++){
        if(s[k]=='R') rgbk[1][0]++;
        if(s[k]=='G') rgbk[1][1]++;
        if(s[k]=='B') rgbk[1][2]++;
    }
    // j > 1 (1 <= j <= n-2)
    for(ll j=2; j<=n-2; j++){
        rgbi[j][0] = rgbi[j-1][0];
        rgbi[j][1] = rgbi[j-1][1];
        rgbi[j][2] = rgbi[j-1][2];
        if(s[j-1]=='R') rgbi[j][0]++;
        if(s[j-1]=='G') rgbi[j][1]++;
        if(s[j-1]=='B') rgbi[j][2]++;

        rgbk[j][0] = rgbk[j-1][0];
        rgbk[j][1] = rgbk[j-1][1];
        rgbk[j][2] = rgbk[j-1][2];
        if(s[j]=='R') rgbk[j][0]--;
        if(s[j]=='G') rgbk[j][1]--;
        if(s[j]=='B') rgbk[j][2]--;
    }

    // for(ll j=1; j<=2; j++) cout << rgbi[j][0] << ' ' << rgbi[j][1] << ' ' << rgbi[j][2] << endl;
    // for(ll j=1; j<=2; j++) cout << rgbk[j][0] << ' ' << rgbk[j][1] << ' ' << rgbk[j][2] << endl;

    ll ret = 0;
    for(ll j=1; j<=n-2; j++){
        if(s[j] == 'R') ret += rgbi[j][1] * rgbk[j][2] + rgbi[j][2] * rgbk[j][1];
        if(s[j] == 'G') ret += rgbi[j][2] * rgbk[j][0] + rgbi[j][0] * rgbk[j][2];
        if(s[j] == 'B') ret += rgbi[j][0] * rgbk[j][1] + rgbi[j][1] * rgbk[j][0];
    }

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