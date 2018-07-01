#include <bits/stdc++.h>
#define MAX_N 500
int N;
int d[MAX_N];
using namespace std;
int main(void){
    cin >> N;
    for(int i=0; i<N; i++) cin >> d[i];
    int max_d = *max_element(d, d+N);
    int sum_d = accumulate(d, d+N, 0);
    cout << sum_d << endl;
    if(sum_d < max_d * 2) cout << max_d * 2 - sum_d << endl;
    else cout << 0 << endl;
    return 0;
}