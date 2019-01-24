#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 10
using namespace std;
int L, N;

int solve(int L, int N, vector<int> _X){
    int ret = 0;
    int ret_bits;
    int MAX_BIT = pow(2, N);
    for(int bits=0; bits<MAX_BIT; bits++){
        vector<int> X(_X);
        int dist = 0;
        int x = 0;
        int _bits = bits;
        for(int i=0; i<N; i++){
            auto j = lower_bound(X.begin(), X.end(), x);
            if(_bits % 2){
                // clockwise go
                j = (j != X.end()) ? j : X.begin();
                dist += (*j > x) ? *j - x : L - x + *j;
            }else{
                // counterclockwise go
                j = (j != X.begin()) ? j - 1: X.end() - 1;
                dist += (x > *j) ? x - *j : x + L - *j;
            }
            x = *j;
            X.erase(j);
            _bits /= 2;
        }
        if(dist > ret){
            ret = dist;
            ret_bits = bits;
        }
    }
    cout << ret << endl;
    for(int i=0; i<N; i++){
        cout << ret_bits % 2;
        ret_bits /= 2;
    }
    cout << endl;
    return 0;
}

int main(void){
    srand (time(NULL));
    int N = 10;
    int L = rand();
    for(int i=0; i<10; i++){
        vector<int> _X(N);
        generate(_X.begin(), _X.end(), 
            [&L]()->int{
                return (rand() % L);
            });
        sort(_X.begin(), _X.end());
        solve(L, N, _X);
    }
    return 0;
}