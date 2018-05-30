/*
 * Contents   : ARC002 C問題
 * Author     : KitauraHiromi
 * LastUpdate : 20180530
 * Since      : 20180530
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(void){
    int N;
    string s;
    cin >> N;
    cin >> s;
    int dp[N+1]; // 0~N文字
    int ret = N;
    string buttons("ABXY");
    vector<string> shortcuts;
    for(char first: buttons){
        for(char second: buttons){
            string shortcut({first, second});
            shortcuts.push_back(shortcut);
        }
    }
    vector< vector <string> > LR_conbo;
    for(auto L: shortcuts){
        for(auto R: shortcuts){
            vector<string> LR({L, R});
            LR_conbo.push_back(LR);
        }
    }
    // DP
    for(auto LR: LR_conbo){
        for(int i=0; i<N+1; ++i) dp[i] = 0;
        dp[1] = 1;
        for(int i=0; i<N-1; ++i){
            if(s.substr(i, 2) == LR[0] or s.substr(i, 2) == LR[1]) 
                dp[i+2] = min(dp[i+1] + 1, dp[i] + 1);
            else
                dp[i+2] = min(dp[i+1] + 1, dp[i] + 2);
        }
        ret = min(ret, dp[N]);
    }
    cout << ret << endl;
}