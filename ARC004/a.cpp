/*
 * Contents   : ARC 004 A
 * Author     : (製作者の名前) (製作者の所属)
 * LastUpdate : (更新日YYYY/MM/DD)
 * Since      : (作成日YYYY/MM/DD)
 */
#include <bits/stdc++.h>
#define MAX_N 100
int N;
int x[MAX_N], y[MAX_N];
using namespace std;
int main(void){
    cin >> N;
    for(int i=0; i<N; i++) cin >> x[i] >> y[i];
    int ret = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int dx, dy;
            dx = x[i] - x[j]; dy = y[i] - y[j];
            ret = max(ret, dx*dx + dy*dy);
        }
    }
    cout << sqrt(ret) << endl;
}