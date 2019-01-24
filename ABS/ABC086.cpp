/*
 * Contents   : AtCoder Beginners Selection 086C AC
 * Author     : KitauraHiromi
 * LastUpdate : 20180525
 * Since      : 20180525
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(void){
    int N;
    int t1, t2, x1, x2, y1, y2;
    t1 = x1 = y1 = 0;
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> t2 >> x2 >> y2;
        if((abs(x2 - x1) + abs(y2 - y1) > (t2 - t1)) || (abs(x2 - x1 + y2 - y1)%2 != (t2 - t1)%2)){
            cout << "No" << endl;
            return 0;
        }
        t1 = t2;
        x1 = x2;
        y1 = y2;
    }
    cout << "Yes" << endl;
    return 0;
}