#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAX_N 510
#define rep(i, n) for(int i=0; i<n; i++)
int n, k, c[MAX_N][MAX_N];

int around(int a, int b){
    return c[(a>0)?a-1:n-1][b] + c[a][(b>0)?b-1:n-1] + c[(a+1<n)?a+1:0][b] + c[a][(b+1<n)?b+1:0];
}

template <size_t N, size_t M>
bool check(int (&c)[N][M]){
    rep(i, k){
        int csum = -1;
        rep(a, n){
            rep(b, n){
                if(c[a][b] == i){
                    if(csum == -1) csum = around(a, b);
                    else if(around(a, b) != csum) return false;
                }
            }
        }
    }
    return true;
}

int solve(int k){
    if(k == 1){
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    n = k / 2;
    n += (k%2==0)?0:1;
    if(n%2==1) n++;
    int _k = 2 * n;

    rep(i, n) rep(j, n) c[i][j] = (j % 2 == 0) ? (i + j) % n : (i + j) % n + n;
    while(_k >= k){
        rep(a, n){
            rep(b, n){
                if(c[a][b] == _k) c[a][b] -= n;
            }
        }
        _k--;
    }

    cout << n << endl;
    rep(i, n){
        rep(j, n) cout << c[i][j] + 1 << " ";
        cout << endl;
    }
}

int main(void){
    cin >> k;
    solve(k);
    return 0;
}