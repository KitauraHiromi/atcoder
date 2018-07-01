#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string tmp;
ll X, Y;
ll calc_gcd(ll x, ll y) {
    if (x == 0) return y;
 
    if (x > y) {
        return calc_gcd(y, x);
    } else {
        return calc_gcd(y % x, x);
    }
}
int main(void){
    bool flag = false;
    cin >> tmp;
    sscanf(tmp.c_str(), "%lld/%lld", &X, &Y);
    ll gcd = calc_gcd(X, Y);
    X /= gcd;
    Y /= gcd;
    // for(ll N=2*X/Y-1; N<=2*X/Y+1; N++){
    ll N = max(1LL, 2*X/Y-2);
    while(Y*(N-1)<=X*2){
        ll sum_N = N*(N+1)/2;
        if(N % Y == 0){
            ll m = sum_N - (N/Y)*X;
            if(m > 0 && m <= N){
                cout << N << ' ' << m << endl;
                flag = true;
            }
        }
        N++;
    }
    if(!flag) cout << "Impossible" << endl;
    return 0;
}