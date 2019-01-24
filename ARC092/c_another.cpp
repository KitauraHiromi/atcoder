/*
 * Contents   : ARC092 C AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180729
 * Since      : 20180729
 * Comment    : 最大マッチングをFord-Fulkersonで求める
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define INF 1<<20
typedef pair<int, int> P;
P r[MAX_N], b[MAX_N];
bool used[2*MAX_N];
int N;
struct edge{int to, cap, rev;};
vector<edge> G[2*MAX_N+2];

void add_edge(int from, int to, int cap){
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size()-1});
}

// 増加パスをdfsで探す
int dfs(int v, int t, int f){
	if(v == t) return f;
	used[v] = true;
	for(int i=0; i<G[v].size(); i++){
		edge &e = G[v][i];
		if(!used[e.to] && e.cap > 0){
			int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0){
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

// sからtへの最大流を求める
int max_flow(int s, int t){
	int flow = 0;
	for(;;){
		fill(used, used+2*N, 0);
		int f = dfs(s, t, INF);
		if(f == 0) return flow;
		flow += f;
	}
}

int main(void){
	cin >> N;
	int s = 2 * N, t = s + 1;
	for(int i=0; i<N; i++){ cin >> r[i].first >> r[i].second; }
	for(int i=0; i<N; i++){ cin >> b[i].first >> b[i].second; }

	for(int i=0; i<N; i++) add_edge(s, i, 1);
	for(int j=0; j<N; j++) add_edge(j+N, t, 1);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(r[i].first < b[j].first && r[i].second < b[j].second) add_edge(i, j+N, 1);
		}
	}
	cout << max_flow(s, t) << endl;
	return 0;
}