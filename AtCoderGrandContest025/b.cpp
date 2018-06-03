#include <iostream>
using namespace std;
int factorial(int k){
    int sum = 1;
    for(int i=1; i<=k; ++i){
        sum *= i;
    }
    return sum;
}
int main(void){
    int N, A, B, K;
    int ret;
    cin >> N >> A >> B >> K;
    for(int i=0; i<=K/A; ++i){
        int j;
        if((K - A*i) % B == 0) j = (K - A*i) / B;
        else continue;
        // cout << "find:" << i << ' ' << j << endl;
        // i, jをもとに色のパターンを決める
        int z = min(i, j);
        int x = i-z; int y = j-z;
        while(x + y + z <= N && z >= 0){
            // cout <<"N:" << N << " 赤:" << x << " 青:" << y << " 緑:" << z << endl;
            ret += (factorial(N) / (factorial(x) * factorial(y) * factorial(z) * factorial(N-x-y-z)));
            ret %= 998244353;
            x += 1; y += 1;
            z -= 1;
        }
    }
    cout << ret << endl;
    return 0;
}