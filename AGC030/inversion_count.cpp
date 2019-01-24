#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAX_N 10000
int n, a[MAX_N], b[MAX_N+1];

int sum(int i){
    int ret=0;
    for(;i>0;i-=i&-i) ret+=b[i];
    return ret;
}

void add(int i, int x){
    for(;i<=n;i+=i&-i) b[i]+=x;
}

void solve(){
    int ret = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        for(int i=0; i<n; i++) cout << sum(i+1) - sum(i) << " ";
        cout << endl;
        ret += i - sum(a[i]);
        add(a[i], 1);
    }
    cout << ret << endl;
}

int main(void){
    solve();
    return 0;
}