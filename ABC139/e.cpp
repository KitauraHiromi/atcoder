#include <bits/stdc++.h>
#define MAX_N 1010
#define MAX_V 1100000
#define mod 1000000007
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, a[MAX_N][MAX_N];

vector<ll> G[MAX_V];  // グラフの隣接リスト表現
vector<ll> rG[MAX_V]; // 辺の向きを逆にしたグラフ
vector<ll> vset;      // 頂点集合
vector<ll> vs;        // 帰りがけ順の並び
bool used[MAX_V];     // 既に調べたか
ll cmp[MAX_V];        // 属する強連結成分のトポロジカル順序
ll depth[MAX_V]       // DAGの深さを格納する配列

void add_edge(ll from, ll to){
  G[from].pb(to);
  rG[to].pb(from);
}

void dfs(ll v){
  used[v] = true;
  for(ll i: G[v]){
    if(!used[i]) dfs(i);
  }
  vs.pb(v);
}

void rdfs(ll v, ll k){
  used[v] = true;
  cmp[v] = k;
  for(ll i: rG[v]){
    if(!used[i]) rdfs(i, k);
    depth[v] = max(depth[v], depth[i]+1);
  }
}
ll scc(){
  fill(used, used+MAX_V, false);
  vs.clear();
  for(auto i: vset){
    if(!used[i]) dfs(i);
  }
  fill(used, used+MAX_V, false);
  ll k = 0;
  vector<ll> rvs(vs.rbegin(), vs.rend());
  for(auto i: rvs){
    if(!used[i]) rdfs(i, k++);
  }
  return k;
}

signed main(){
  cin >> n;
  ll v = n * (n - 1) / 2;
  REP(i, n) REP(j, n-1){ cin >> a[i][j]; a[i][j]--;}
  REP(i, n) REP(j, n-2){
    ll from = min(i, a[i][j]) * n + max(i, a[i][j]);
    ll to = min(i, a[i][j+1]) * n + max(i, a[i][j+1]);
    add_edge(from, to);
  }
  REP(i, n) for(ll j=i+1; j<n; j++) vset.pb(i*n + j);

  ll k = scc();
  if(k != v) cout << -1 << endl;
  else{
    ll ret = 0;
    for(auto a: vset) ret = max(ret, depth[a]);
    cout << ret + 1 << endl;
  }
  return 0;
}