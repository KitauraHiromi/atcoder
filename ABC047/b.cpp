#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int w, h, n;

signed main(){
    cin >> w >> h >> n;
    int l, r, t, b;
    l = 0; r = w; t = h, b = 0;
    REP(i, n){
        int x, y, a;
        cin >> x >> y >> a;
        if(a==2) r = min(r, x);
        else if(a==1) l = max(l, x);
        else if(a==4) t = min(t, y);
        else if(a==3) b = max(b, y);
    }
    if(l<r && t>b) cout << (r-l)*(t-b) << endl;
    else cout << 0 << endl;


    return 0;
}