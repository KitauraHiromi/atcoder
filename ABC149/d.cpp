#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 100001
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) for(int i=0; i<n; i++)
#define RER(i, n) for(int i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, k, r, s, p;
string t;
char choice[3] = {'r', 's', 'p'};

signed main(void){
    cin >> n >> k;
    cin >> r >> s >> p;
    cin >> t;

    int ret = 0;
    for(int i=0; i<k; i++){
        char prev = 'a';
        for(int j=i; j<n; j+=k){
            if(j < k || t[j] != prev){
                if(t[j] == 'r'){
                    ret += p;
                    prev = 'r';
                }
                else if(t[j] == 's'){
                    ret += r;
                    prev = 's';
                }
                else if(t[j] == 'p'){
                    ret += s;
                    prev = 'p';
                }
            }else{
                prev = 'a';
            }
        }
    }
    cout << ret << endl;
}