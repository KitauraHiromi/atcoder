#include <vector>
#include <iostream>
using namespace std;

int make_table(vector< vector<int> > &v){
    int n = v.size();
    if(n < 3) return 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j%2==0) v[i][j] = (i + j) % n;
            else v[i][j] = (i + j) % n + n;
        }
    }
    return 0;
}

int paded_table(vector< vector<int> > &v, int n){
    vector< vector<int> > small_v(n, vector<int>(n, -1));
    make_table(small_v);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v[i+1][j+1] = small_v[i][j];
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            if(0 < i && i < n) if(0 < j && j < n) continue;
            if(v[(i+n-2)%n][j] != -1) v[i][j] = v[(i+n-2)%n][j];
            if(v[i][(j+n-2)%n] != -1) v[i][j] = v[i][(j+n-2)%n];
            if(v[(i+n-2)%n][(j+n-2)%n] != -1) v[i][j] = v[(i+n-2)%n][(j+n-2)%n];
        }
    }
    return 0;
}

int main(void){
    int n;
    cin >> n;
    vector< vector<int> > v(n, vector<int>(n, -1));
    paded_table(v, n-2);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}