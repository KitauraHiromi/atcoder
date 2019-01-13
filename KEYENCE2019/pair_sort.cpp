#include <bits/stdc++.h>
#include <utility>
#include <iostream>
using namespace std;
#define MAX_N 100
#define rep(i, n) for(int i=0; i<n; i++)
typedef pair<int, int> P;
P p[MAX_N];
int n;
int main(){
    cin >> n;
    rep(i, n){
        cin >> p[i].first;
        p[i].second = i;
    }
    rep(i, n){
        cout << p[i].first << " " << p[i].second << endl;
    }
    sort(p, p+n);
    rep(i, n){
        cout << p[i].first << " " << p[i].second << endl;
    }
    sort(p, p+n, [](auto &left, auto &right){
        return left.second < right.second;
    });
    rep(i, n){
        cout << p[i].first << " " << p[i].second << endl;
    }
    return 0;
}