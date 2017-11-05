#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

int main(void){
    long long int N, C;
    cin >> N >> C;
    array<int, 100000> L;
    int x = 0;

    for(int i=0; i<N; ++i){
        cin >> L[i];
    }
    sort(L.begin(), L.begin()+N);
    int i = 0;
    int j = N-1;
    while(i < j){
        if(L[i] + L[j] + 1 <= C){
            ++i;
            --j;
            ++x;
        }else{
            --j;
            ++x;
        }
    }
    if(i == j) ++x;
    cout << x << endl;
}