    #include <bits/stdc++.h>
    #include <iostream>
    #include <utility> // pair
    #include <string>
    #include <vector>
    #include <algorithm>
    #define MAX_N 200001
    using namespace std;
    using ll = long long;
    using P = pair<ll, ll>;
    #define FOR(i, a, b) for(ll i=a; i<b; i++)
    #define REP(i, n) for(ll i=0; i<n; i++)
    #define REV(i, n) for(ll i=n-1; i>=0; i--)
    #define ALL(v) v.begin(), v.end()
    #define pb push_back
    const ll INF = 9e18;
    ll n;
    vector<ll> v, cnt;

    signed main(){
        cin >> n;
        v.resize(n);
        REP(i, n) v[i] = i;
        cnt.resize(n, 0);
        do{
            ll pos = 0, mini = INF;
            REP(i, n){
                if(v[i] == 0) pos = i;
            }
            REP(i, n){
                if(pos > i) mini = min(v[i], mini);
            }
            // cout << mini << endl;
            if(mini != INF) cnt[mini-1]++;
            else cnt[n-1]++;
        }while(next_permutation(v.begin(), v.end()));

        REP(i, n) cout << cnt[i] << " ";
        cout << endl;
        return 0;
    }