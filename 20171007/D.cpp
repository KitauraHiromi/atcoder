#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
#include<math.h>
using namespace std;

int H, W, A, B;
array<char, 200*200> grid;
vector<int> list;
vector<int> happiness;

vector<int> eval(int i, int N){
    vector<int> tmp;
    for(int k=0; k<=log2(N); ++k){
        int idx = pow(2, k);
        if(idx < N) tmp.push_back(idx);
    }
    vector<int> hapi;
    for(int e: tmp){
        hapi.push_back(happiness[e]);
    }
    return hapi;
}

int main(void){
    cin >> H >> W >> A >> B;
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            cin >> grid[H*i+j];
            if(grid[H*i+j] == 'S') list.push_back(H*i+j);
        }
    }
    long long int N = pow(2, list.size());
    happiness.assign(N, 0);
    for(int i=0; i<N; ++i){
        vector<int> tmp = eval(i, N);
        happiness[i] = *max(tmp.begin(), tmp.end());
    }
    cout << happiness[N-1] << endl;
}