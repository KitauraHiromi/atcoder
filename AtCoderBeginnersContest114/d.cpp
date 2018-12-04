#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> p, a;
bool is_primitive(int n){
    for(int j=2; j*j<=n; j++){
        if(n % j == 0) return false;
    }
    return true;
}
int main(void){
    cin >> N;
    // 素数を取り出す
    for(int i=2; i<=N; i++){
        if(is_primitive(i)){
            p.push_back(i);
        }
    }
    // 素因数の数を計算
    for(int i=0; i<p.size(); i++){
        int n = N;
        a.push_back(0);
        while(n > 1){
            n /= p[i];
            a[i] += n;
        }
    }
    // 75の作り方
    // 1. 3x5x5
    // 2. 3x25
    // 3. 15x5
    // 4. 75
    int ret = 0;
    // 1. 3x5x5
    int l = 0, m = 0;
    for(auto e: a){
        if(e >= 2) l++;
        if(e >= 4) m++;
    }
    ret += (l - m) * m * (m - 1)/ 2;
    ret += m * (m - 1) * (m - 2) / 2;

    // 2. 3x25
    l = m = 0;
    for(auto e: a){
        if(e >= 2) l++;
        if(e >= 24) m++;
    }
    ret += (l - m) * m;
    ret += m * (m - 1);

    // 3. 5x15
    l = m = 0;
    for(auto e: a){
        if(e >= 4) l++;
        if(e >= 14) m++;
    }
    ret += (l - m) * m;
    ret += m * (m - 1);

    // 4. 75
    l = m = 0;
    for(auto e: a){
        if(e >= 74) l++;
    }
    ret += l;

    cout << ret << endl;

}