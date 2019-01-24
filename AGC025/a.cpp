/*
 * Contents   : AGC025 A AC
 * Author     : KitauraHiromi
 * LastUpdate : 20180603
 * Since      : 20180603
 */
#include <iostream>
using namespace std;
int digit_sum(int x){
    int ret = 0;
    ret += x / 100000; x %= 100000;
    ret += x / 10000; x %= 10000;
    ret += x / 1000; x %= 1000;
    ret += x / 100; x %= 100;
    ret += x / 10; x %= 10;
    ret += x;
    return ret;
}

int main(void){
    int N, ret;
    cin >> N;
    ret = 1000000007;
    for(int A=1; A<N; ++A){
        int B = N - A;
        // cout << A << ' ' << digit_sum(A) << ' ' << B << ' ' << digit_sum(B) << endl;
        ret = min(ret, digit_sum(A) + digit_sum(B));
    }
    cout << ret << endl;
    return 0;
}