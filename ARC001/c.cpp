/*
 * Contents   : ARC001 C問題 WA
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180526
 * Since      : 20180526
 */
#include <iostream>
#include <stack>
#include <set>
#include <vector>
using namespace std;

void print_state(set<vector<int>> state){
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            vector<int> tmp({i, j});
            if(state.count(tmp) == 0) cout << '.';
            else cout <<'Q';
        }
        cout << endl;
    }
}

vector<vector<int> > possible_pos(set<vector<int>> state){
    vector< vector<int> > ret;
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            bool pass = true;
            vector<int> tmp({i, j});
            for(auto pos: state)
                if(i == pos[0] || j == pos[1] || abs(i - pos[0]) - abs(j - pos[1]) == 0) pass = false;
            if(pass)
                ret.push_back(tmp);
        }
    }
    return ret;
}

bool state_pass(set<vector<int>> state){
    for(auto q_i: state){
        for(auto q_j: state){
            if(q_i != q_j)
                if(q_i[0] == q_j[0] || q_i[1] == q_j[1] || abs(q_i[0] - q_j[0]) - abs(q_i[1] - q_j[1]) == 0)
                    return false;
        }
    }
    return true;
}

int main(void){
    // dfs
    // 状態はクイーンの置かれている座標のセット
    stack< set< vector<int>> > st;
    set<vector<int>> start;
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            char c;
            cin >> c;
            if(c == 'Q'){
                vector<int> q({i, j});
                start.insert(q);
            }
        }
    }

    st.push(start);
    // cout << "start state" << endl;
    // for(auto pos: start)
    //     cout << pos[0] << ' ' << pos[1] << endl;
    // // test possible_pos
    // cout << "possible pos" << endl;
    // auto poses = possible_pos(start);
    // for(auto pos: poses)
    //     cout << pos[0] << ' ' << pos[1] << endl;

    while(!st.empty()){
        auto state = st.top(); st.pop();
        if(!state_pass(state)) break;
        for(auto pos: possible_pos(state)){
            // コピーコンストラクタ
            set<vector<int>> new_state(state);
            new_state.insert(pos);
            if(new_state.size() == 8){
                print_state(new_state);
                return 0;
            }
            st.push(new_state);
        }
    }
    cout << "No Answer" << endl;
    return 0;
}
