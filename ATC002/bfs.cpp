/*
Contents   : AtCoder Typical Contest 002
Author     : Kitaura Hiromi
LastUpdate : 20180523
Since      : 20180522
*/
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // read map
    int R, C;
    cin >> R >> C;
    auto map = vector< vector<int> >(R, vector<int>(C, -1)); // スタートからの距離を保持(-1:未到達, 0:進入不可)
    
    // read start and goal
    vector<int> start(2, -1);
    vector<int> goal(2, -1);
    cin >> start[0] >> start[1]; start[0] -= 1; start[1] -= 1;
    cin >> goal[0] >> goal[1]; goal[0] -= 1; goal[1] -= 1;
    // cout << "start " << start[0] << ' ' << start[1] << endl;;
    // cout << "goal " << goal[0] << ' ' << goal[1] << endl;;

    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            char c;
            cin >> c;
            if(c == '#'){
                map[i][j] = 0;
            }
        }
    }

    queue< vector<int> > q; // 探索順番を保持
    q.push(start);
    map[start[0]][start[1]] = 0;
    bool get_to_goal = false;
    // 進行方向を定義
    auto dirs = vector< vector<int>>(4, vector<int>(2, 0));
    dirs[0][0] = 1; dirs[1][0] = -1;
    dirs[2][1] = 1; dirs[3][1] = -1;

    int dist = 0;
    while(!get_to_goal || q.empty()){
        // キューの先頭を取得
        auto p = q.front(); q.pop();
        dist = map[p[0]][p[1]] + 1;
        for(auto dir: dirs){
            int i = dir[0]; int j = dir[1];
            if(map[p[0]+i][p[1]+j] < 0){
                // キューの先頭の隣接位置の距離を確定
                map[p[0]+i][p[1]+j] = dist;
                // 距離を確定させたマスをキューに追加する
                vector<int> tmp{p[0]+i, p[1]+j};
                q.push(tmp);
                // cout << p[0]+i << ' ' << p[1]+j << ' ' << map[p[0]+i][p[1]+j] << endl;
            }
        }
        if(p == goal){
            get_to_goal = true;
            cout << map[goal[0]][goal[1]] << endl;
            return 0;
        }
    }
    return 1;
}