/*
 * Contents   : ARC003 C問題 AC
 * Author     : KitauraHiromi
 * LastUpdate : 20180601
 * Since      : 20180531
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

vector<int> start, goal;
bool get_to_goal;
vector<string> map;
// vector<vector<int>> strides;
double dx[] = {0, 1, 0, -1};
double dy[] = {1, 0, -1, 0};
int N, M;

double brightness(char c, int t){
    int int_c = c - '0';
    return int_c * pow(0.99, t);
}

bool bfs(double mid){
    queue<vector<int>> q;
    queue<int> time_q;
    get_to_goal = false;
    q.push(start);
    auto t = vector<vector<int>>(N+2, vector<int>(M+2, -1));
    t[start[0]][start[1]] = 0;

    while(!q.empty()){
        // キューから状態を一つ取り出す
        auto s = q.front(); q.pop();
        for(int i=0; i<4; ++i){
            vector<int> ns(s); // next state
            ns[0] += dx[i]; ns[1] += dy[i];
            // 判定
            if(map[ns[0]][ns[1]] == 'g') return true;
            // sから行ける場所をキューに追加
            if(map[ns[0]][ns[1]] != '#' && map[ns[0]][ns[1]] != 's' && t[ns[0]][ns[1]] < 0){
                t[ns[0]][ns[1]] = t[s[0]][s[1]] + 1;
                if(brightness(map[ns[0]][ns[1]], t[ns[0]][ns[1]]) >= mid){
                    q.push(ns);
                }
            }
        }
    }
    return false;
}

int main(void){
    // 地図を読み込む. 外周は#で囲む.
    cin >> N >> M;
    string margin(M+2, '#');
    map.push_back(margin);
    for(int i=0; i<N; ++i){
        string tmp;
        cin >> tmp;
        map.push_back("#" + tmp + "#");
    }
    map.push_back(margin);
    // start goalを取得
    for(int i=0; i<N+2; ++i){
        for(int j=0; j<M+2; ++j){
            if(map[i][j] == 's') start = {i, j};
            if(map[i][j] == 'g') goal = {i, j};
        }
    }

    if(!bfs(-1)){
        cout << -1 << endl;
        return 0;
    }
    // 二分探索
    double l = 0, r = 10, mid = 5;
    while(r - l > 1e-10){
        mid = (l + r) / 2.;
        if(bfs(mid)) l = mid;
        else r = mid;
    }
    cout << setprecision(15) << mid << endl;
    return 0;
}