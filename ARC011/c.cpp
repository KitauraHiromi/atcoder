/*
 * Contents   : ARC011 C問題 AC
 * Author     : Kitaura Hiromi
 * LastUpdate : 20180722
 * Since      : 20180720
 */
#include <bits/stdc++.h>
#define MAX_N 1002
using namespace std;
struct node{
	string word;
	vector<int> to;
	int id;
	int from;
};
node nodes[MAX_N];
int N;
string start, goal;
int visited[MAX_N];

bool check(string a, string b){
	int diff = 0;
	for(int i=0; i<a.size(); i++)
		if(a[i] != b[i]) diff++;
	if(diff == 1) return true;
	else return false;
}

int main(void){
	cin >> start >> goal;
	cin >> N;
	fill(visited, visited+MAX_N, -1);
	nodes[0].word = start; nodes[0].id = 0;
	nodes[1].word = goal; nodes[1].id = 1;
	// グラフの構築
	for(int i=2; i<N+2; i++){
		string tmp;
		cin >> tmp;
		if(tmp != start && tmp != goal){
			nodes[i].word = tmp;
			nodes[i].id = i;
		}
	}

	if(start == goal){
		cout << 0 << endl;
		cout << start << endl;
		cout << goal << endl;
	}

	// 一文字違いのノードを結ぶ
	for(int i=0; i<N+2; i++){
		for(int j=0; j<i; j++){
			if(check(nodes[i].word, nodes[j].word)){
				// cout << "add " << i << ' ' << j << endl; 
				nodes[i].to.push_back(j);
				nodes[j].to.push_back(i);
			}
		}
	}

	// check
	// cout << nodes[0].id << ' ' << nodes[0].word << ' ';
	// for(auto i: nodes[0].to){
	// 	cout << nodes[i].id << ' ' << nodes[i].word << ' ';
	// }
	// cout << endl;

	// bfs
	queue<node> q;
	q.push(nodes[0]);
	visited[0] = 0;
	while(!q.empty()){
		auto state = q.front(); q.pop();
		if(state.id == 1) break;
		for(int id: state.to){
			if(visited[id] < 0){
				q.push(nodes[id]);
				nodes[id].from = state.id;
				visited[id] = visited[state.id] + 1;
			}
		}
	}
	if(visited[1] < 0){
		cout << -1 << endl;
	}else{
		// print result
		cout << visited[1] - 1 << endl;
		int id = 1;
		vector<string> ret;
		while(id != 0){
			ret.push_back(nodes[id].word);
			id = nodes[id].from;
		}
		ret.push_back(nodes[0].word);
		for(int i=ret.size()-1; i>=0; i--) cout << ret[i] << endl;
	}
	return 0;
}