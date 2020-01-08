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
int n;

bool is_prime(int x){
    for(int i=2; i*i<x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

signed main(void){
    cin >> n;
    for(int i=n; i<10*n; i++){
        if(is_prime(i)){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}