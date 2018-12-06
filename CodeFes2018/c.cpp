#include <bits/stdc++.h>
#define MAX_N 100001
typedef long long ll;
using namespace std;
ll N, x[MAX_N];
ll dist[MAX_N];
int main(void){
    cin >> N;
    for(ll i=0; i<N; i++) cin >> x[i];

    sort(x, x+N);
    dist[N-1] = 0;
    for(ll i=N-2; i>=0; i--){
        dist[i] = dist[i+1] + x[i+1];
    }
    ll ret = 0;
    for(ll i=0; i<N-1; i++){
        ret += dist[i] - (N - i - 1) * x[i];
    }
    cout << ret << endl;
}