#include<bits/stdc++.h>
#define MAX_H 500
#define MAX_W 500
using namespace std;
int H, W;
pair<int, int> start, goal;
char c[MAX_H][MAX_W];
bool visited[3][MAX_H][MAX_W];
struct state
{
	pair<int, int> xy;
	int res; // 壁を壊せる残り回数
};
stack<state> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main(){
	cin >> H >> W;
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cin >> c[i][j];
			if(c[i][j] == 's') start = {i, j};
			else if(c[i][j] == 'g') goal = {i, j};
		}
	}
	fill((bool*)visited, (bool*)visited+3, false);
	state a; a.xy = start; a.res = 2; 
	q.push(a);
	while(!q.empty()){
		auto s = q.top(); q.pop();
		visited[s.res][s.xy.first][s.xy.second] = true;
		if(s.xy == goal){
			cout << "YES" << endl;
			return 0;
		}
		cout << s.xy.first << ' ' << s.xy.second << endl;
		for(int k=0; k<4; k++){
			state b;
			b.xy.first = s.xy.first + dx[k];
			b.xy.second = s.xy.second + dy[k];
			b.res = s.res;
			int i = b.xy.first, j = b.xy.second;
			if(i >= 0 && i < H && j >= 0 && j < W){
				if(c[i][j] == '#') b.res--;
				if(b.res >= 0)
					if(!visited[b.res][i][j]) q.push(b);
			}
		}
	}
	cout << "NO" << endl;
}