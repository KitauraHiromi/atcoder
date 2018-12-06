#include <bits/stdc++.h>
using namespace std;
int x, y;
int main(void){
    cin >> x >> y;
    while((x >= 3 && y >= 1) || (x >= 1 && y >= 3)){
        if(x > y){
            x -= 3; y -= 1;
        }else{
            y -= 3; x -= 1;
        }
    }
    if(x == 0 && y == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}