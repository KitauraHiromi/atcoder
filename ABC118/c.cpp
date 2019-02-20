#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 101
#define rep(i, a, b) for(int i=a; i<b; i++)
#define rer(i, a, b) for(int i=a-1; i>=b; i--)
#define pb push_back
using namespace std;
typedef pair<int, int> P;
int n;
int v[MAX_N][3];

signed main(){
    cin >> n;
    rep(i, 0, n){
        int x, y, h;
        cin >> x >> y >> h;
        v[i][0] = x; v[i][1] = y; v[i][2] = h;
    }
    int s=0; rep(i, 0, n) if(v[i][2] != 0) s = i;
    rep(i, 0, MAX_N){
        rep(j, 0, MAX_N){
            bool ok = true;
            int h = v[s][2] + abs(v[s][0] - i) + abs(v[s][1] - j);
            rep(k, 0, n){
                if(v[k][2] != max(0, h - abs(v[k][0] - i) - abs(v[k][1] - j))) ok = false;
            }
            if(ok){
                cout << i << " " << j << " " << h << endl;
                return 0;
            }
        }
    }
}