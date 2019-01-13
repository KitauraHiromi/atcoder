#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n[4];
int main(){
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    sort(n, n+4);
    if(n[0]==1) if(n[1]==4) if(n[2]==7) if(n[3]==9){
        cout <<"YES"<<endl;
        return 0;
    }
    cout <<"NO" << endl;
    return 0;
}