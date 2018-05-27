/*
 * Contents   : ARC001 A問題 AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180525
 * Since      : 20180525
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    string c;
    cin >> N;
    cin >> c;
    vector<int> v(4, 0);
    for(int i=0; i<N; ++i){
        if(c[i]=='1') v[0] += 1;
        else if(c[i]=='2') v[1] += 1;
        else if(c[i]=='3') v[2] += 1;
        else v[3] += 1;
    }
    auto max_iter = max_element(v.begin(), v.end());
    auto min_iter = min_element(v.begin(), v.end());
    cout << *max_iter << ' ' << *min_iter << endl;
}