#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define INF 1e15
#define MAX_N 1000001
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define RER(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin() v.end()
#define pb push_back
using namespace std;
typedef long long ll;
struct edge{ll to, cost;};
typedef pair<ll, ll> P;
ll n, q, k;
vector<edge> G[MAX_N];
ll d[MAX_N], x[MAX_N], y[MAX_N];

void dijkstra(ll s){
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + n + 10, INF);
	d[s] = 0;
	que.push(P(0, s));

	while(!que.empty()){
		P p = que.top(); que.pop();
		ll v = p.second;
		if(d[v] < p.first) continue;
		for(edge e: G[v]){
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

signed main(){
	cin >> n;
	REP(i, n-1){
		ll a, b, c; cin >> a >> b >> c;
		edge e1, e2;
		e1.to = a; e1.cost = c;
		e2.to = b; e2.cost = c;
		G[a].pb(e2);
		G[b].pb(e1);
	}

	cin >> q >> k;
	dijkstra(k);
	REP(i, q){
		cin >> x[i] >> y[i];
	}
	REP(i, q) cout << d[x[i]] + d[y[i]] << endl;
    return 0;
}