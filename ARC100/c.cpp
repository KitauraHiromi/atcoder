/*
 * Contents   : ARC 100 C AC
 * Author     : KitauraHiromi
 * LastUpdate : 20180701
 * Since      : 20180701
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll N;
ll a[200010];
int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a, a+N);
    ll sad = 0;
    for(int i=0; i<N; i++){
        sad += abs(a[i] - a[N/2]);
    }
    cout << sad << endl;
}