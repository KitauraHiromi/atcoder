/*
 * Contents   : AGC D問題 TLE
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180607
 * Since      : 20180607
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
vector<P> move1, move2;
int col[601][601];
bool used[601][601];

using namespace std;
int main(void){
    int N, D1, D2;
    cin >> N >> D1 >> D2;
    for(int i=0; i<2*N; ++i){
        for(int j=0; j<2*N; ++j){
            int d = i*i + j*j;
            if(d == D1){
                move1.push_back(P(i, j));
                move1.push_back(P(-i, j));
                move1.push_back(P(i, -j));
                move1.push_back(P(-i, -j));
            }
            if(d == D2){
                move2.push_back(P(i, j));
                move2.push_back(P(-i, j));
                move2.push_back(P(i, -j));
                move2.push_back(P(-i, -j));
            }
        }
    }
    // 格子の各点からdfsで全点を彩色していく
    //    D1  D2
    // 0: a - a
    // 1: a - b
    // 2: b - a
    // 3: b - b
    memset(col, 0, sizeof(col));
    memset(used, false, sizeof(used));
    for(int i=0; i<2*N; ++i){
        for(int j=0; j<2*N; ++j){
            if(col[i][j] != 0) continue;
            // dfs
            queue<array<int, 3>> q;
            q.push(array<int, 3>({i, j, 0}));
            while(!q.empty()){
                auto s = q.front(); q.pop();
                int x = s[0]; int y = s[1]; int c = s[2];
                col[x][y] += c<<0;
                c = 1 - c; // 隣接する色は異なる
                for(auto step: move1){
                    int dx = step.first; int dy = step.second;
                    if(x+dx < 2*N && 0 <= x+dx && y+dy < 2*N && 0 <= y+dy){
                        if(col[x+dx][y+dy] == 0){
                            q.push(array<int, 3>({x+dx, y+dy, c}));
                        }
                    }
                }
            }
        }
    }
    memset(used, false, sizeof(used));
    for(int i=0; i<2*N; ++i){
        for(int j=0; j<2*N; ++j){
            if(col[i][j] != 0) continue;
            // dfs
            queue<array<int, 3>> q;
            q.push(array<int, 3>({i, j, 0}));
            while(!q.empty()){
                auto s = q.front(); q.pop();
                int x = s[0]; int y = s[1]; int c = s[2];
                col[x][y] += c<<1;
                c = 1 - c; // 隣接する色は異なる
                for(auto step: move2){
                    int dx = step.first; int dy = step.second;
                    if(x+dx < 2*N && 0 <= x+dx && y+dy < 2*N && 0 <= y+dy){
                        if(col[x+dx][y+dy] == 0){
                            q.push(array<int, 3>({x+dx, y+dy, c}));
                        }
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<2*N; ++i){
        for(int j=0; j<2*N; ++j){
            if(col[i][j] == 0){
                if(++cnt > N*N) return 0;
                cout << i << ' ' << j << endl;
            }
        }
    }
    return 0;
}