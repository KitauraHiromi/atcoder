#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAX_N 100001
typedef long long ll;
ll a[MAX_N], b[MAX_N], c[MAX_N], n;
int main(){
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    ll nd = 0, ne = 0;
    for(ll i=0; i<n; i++){
        cin >> b[i];
        c[i] = a[i] - b[i];
    }
    sort(c, c+n);
    ll sum=0;
    for(int i=0; i<n; i++){
        sum += c[i];
    }
    if(sum < 0){
        cout << -1 << endl;
        return 0;
    }

    int i=0, j=n-1;
    ll tmp_cj = c[j];
    while(c[j]>0 && c[i]<0){
        if(c[j] > -c[i]){
            c[j] += c[i];
            c[i] = 0;
            i++;
        }else{
            c[i] += c[j];
            c[j] = 0;
            j--;
            tmp_cj = c[j];
        }
    }
    if(tmp_cj == c[j]) cout << i + (n - 1 - j) << endl;
    else cout << i + (n - 1 - j) + 1 << endl;
    return 0;
}