/*
 * Contents   : (プロジェクト全体の役割)
 * Author     : (製作者の名前) (製作者の所属)
 * LastUpdate : (更新日YYYY/MM/DD)
 * Since      : (作成日YYYY/MM/DD)
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> next_day(vector<int> ymd){
    vector<int> ret(ymd);
    // 年末
    if(ymd[1] == 12 && ymd[2] == 31){
        ret[0] += 1; ret[1] = 1; ret[2] = 1;
        // 月末処理 1,3,5,7,8,10, 12月
    }else if(ymd[1] == 1 || ymd[1] == 3 || ymd[1] == 5 || ymd[1] == 7 || ymd[1] == 8 || ymd[1] == 10 || ymd[1] == 12){
        if(ymd[2] == 31){ ret[1] += 1; ret[2] = 1; }
        else{ ret[2] += 1; }
        // 月末処理 4, 6, 9, 11月
    }else if(ymd[1] == 4 || ymd[1] == 6 || ymd[1] == 9 || ymd[1] == 11){
        if(ymd[2] == 30){ ret[1] += 1; ret[2] = 1; }
        else{ ret[2] += 1; }
        // 月末処理 2月
    }else{
        // 非うるう年
        if(ymd[0] % 4 != 0 ||(ymd[0] % 100 == 0 && ymd[0] % 400 == 0)){
            if(ymd[2] == 28){ ret[1] += 1; ret[2] = 1; }
            else{ ret[2] += 1; }
        // うるう年
        }else{ 
            if(ymd[2] == 29){ ret[1] += 1; ret[2] = 1; }
            else{ ret[2] += 1; }
        }
    }
    return ret;
}

bool dividable(vector<int> ymd){
    if(ymd[0] % (ymd[1] * ymd[2]) == 0) return true;
    else return false;
}

int main(void){
    int y, m, d;
    cin >> y >> m >> d;
    vector<int> ymd({y, m, d});
    while(!dividable(ymd)){
        ymd = next_day(ymd);
    }
    cout << ymd[0] << '/' << ymd[1] << '/' << ymd[2] << endl;
    return 0;
}