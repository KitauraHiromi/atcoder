/*
 * Contents   : ARC002 A問題 AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180528
 * Since      : 20180528
 */
using namespace std;
#include <iostream>
int main(void){
    int y;
    cin >> y;
    // if(y % 4 == 0){
    //     if(y % 100 == 0){
    //         if(y % 400 == 0){
    //             cout << "YES" << endl;
    //              return 0;
    //         }else{
    //             cout << "NO" << endl;
    //             return 0;
    //         }
    //     }else{
    //         cout << "YES" << endl;
    //         return 0;
    //     }
    // }
    // cout << "NO" << endl;
    // return 0;

    if(y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) 
        cout << "NO" << endl;;
    else 
        cout << "YES" << endl;
    return 0
}