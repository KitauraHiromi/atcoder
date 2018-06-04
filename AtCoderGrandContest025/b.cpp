#include <iostream>
#include <vector>
using namespace std;

const long long mod = 998244353;

long long modpow(long long a, long long b) {
    if (b == 0) return 1;
    return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}

long long modinv(long long a) {
    return modpow(a, mod - 2);
}

inline long long  inverse(long long  a, long long  m) {
    long long  b = m, u = 1, v = 0;
    while (b) {
        long long  t = a / b;
        swap(a -= t * b, b);
        swap(u -= t * v, v);
    }
    return (u % m + m) % m;
}


vector<long long> fact, inv_fact;
void init_fact(long long n) {
    fact.resize(n);
    fact[0] = 1;
    for (long long i = 1; i < n; i++) {
        fact[i] = i * fact[i - 1] % mod;
    }
    inv_fact.resize(n);
    inv_fact[n - 1] = inverse(fact[n - 1], mod);
    for (long long i = n - 2; i >= 0; i--) {
        inv_fact[i] = (i + 1) * inv_fact[i + 1] % mod;
    }
}

long long nPr(long long n, long long r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fact[n] * inv_fact[n - r] % mod;
}

long long nCr(long long n, long long r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

long long nHr(long long n, long long r) {
    if (n == 0 && r == 0) return 1;
    return nCr(n + r - 1, r);
}


long long factorial(long long k){
    long long sum = 1;
    for(long long i=1; i<=k; ++i){
        sum *= i;
    }
    return sum;
}

int main(void){
    long long N, A, B, K;
    long long ret;
    cin >> N >> A >> B >> K;
    init_fact(N+1);
    for(long long i=0; i<=K/A; ++i){
        long long j;
        if((K - A*i) % B == 0) j = (K - A*i) / B;
        else continue;

        ret += nCr(N, i) * nCr(N, j);
        ret %= mod;

        // cout << "find:" << i << ' ' << j << endl;
        // i, jをもとに色のパターンを決める
        // long long z = min(i, j);
        // long long x = i-z; long long y = j-z;
        // while(x + y + z <= N && z >= 0){
        //     // cout <<"N:" << N << " 赤:" << x << " 青:" << y << " 緑:" << z << ' ' << endl;
        //     // cout << nCr(N, x+y+z) << ' ' << nCr(x+y+z, y+z) << ' ' << nCr(y+z, y) << endl;
        //     ret += nCr(N, x+y+z) * nCr(x+y+z, x) * nCr(y+z, z);
        //     ret %= 998244353;
        //     x += 1; y += 1;
        //     z -= 1;
        // }
    }
    cout << ret << endl;
    return 0;
}