#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int A, B, C;
int main(){
    cin >> A >> B >> C;
    cout << min(A + B + 1, C) + B << endl;
    return 0;
}