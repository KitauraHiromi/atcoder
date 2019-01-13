#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string s, keyence("keyence");
int main(){
    cin >> s;
    if(s.substr(0, 7) == keyence){ cout << "YES" << endl; return 0;}
    if(s.substr(s.size()-7, 7) == keyence){ cout << "YES" << endl; return 0;}
    for(int i=0; i<s.size() ;i++){
        for(int j=i; j<s.size(); j++){
            if(s.substr(0, i) + s.substr(j, s.size()-j) == keyence){
                cout <<"YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}