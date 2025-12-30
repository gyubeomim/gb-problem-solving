#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>
#include <algorithm>
#include <cstring>

#define pii pair<int,int>
#define ll long long

using namespace std;

#define ISLAND_MAX 7
#define MAX 10
#define INF 1000

int N,M;
int ans = INF;
int board[11][11] = {0};
int label[11][11] = {0};

int dist[ISLAND_MAX][ISLAND_MAX] = {0};

int area_num;

vector<pii> v;
vector<pii> area_pos[ISLAND_MAX];
vector<pair<pair<int,int>,int>> bridge_list;

bool ck[11][11];
bool comb[ISLAND_MAX];
bool connect[ISLAND_MAX][ISLAND_MAX];
bool connect_island[ISLAND_MAX];

const int dr[4] = {-1,1,0,0};
const int dc[4] = {0,0,-1,1};

void BFS(int a, int b, int num) {
	
	queue<int> q;
	q.push(a*10+b);
	ck[a][b] = true;
	label[a][b] = num;
	area_pos[num].push_back(make_pair(a,b));

	while(!q.empty()) {
		int r = q.front() / 10;
		int c = q.front() % 10;
		q.pop();
		
		for(int d=0; d<4; d++){
			int nr = r + dr[d];
			int nc = c + dc[d];
			
			if(nr<0 || nr>N-1 || nc<0 || nc>M-1) continue;
			if(ck[nr][nc]) continue;
			if(board[nr][nc] == 0) continue;

			q.push(nr*10 + nc);
			ck[nr][nc] = true;
			label[nr][nc] = num;
			area_pos[num].push_back(make_pair(nr,nc));
		}
	}
}

void MakeLabels() {
	int label_num = 1;

	for(int i=0; i<v.size(); i++){
		int x = v[i].first;
		int y = v[i].second;

		if(!ck[x][y]){
			BFS(x,y,label_num++);
		}
	}

	area_num = label_num;
}

void DFS(int r, int c, int d, int len, int isnum1, int isnum2) {
	int nr = r + dr[d];
	int nc = c + dc[d];
	if(nr<0 || nr>N-1 || nc<0 || nc>M-1) return;

	if(board[nr][nc] == 0) {
		DFS(nr, nc, d, len+1, isnum1, isnum2);
	}
	else if(board[nr][nc] == 1) {
		if(label[nr][nc] == isnum2) {
			if(len > 1) {
				if(dist[isnum1][isnum2] > len) {
					dist[isnum1][isnum2] = len;
					dist[isnum2][isnum1] = len;
				}
				return;
			}
		}
		else return;
	}
}

void MakeBridge(int isnum1, int isnum2) {
	for(int i=0; i<area_pos[isnum1].size(); i++){
		int r = area_pos[isnum1][i].first;
		int c = area_pos[isnum1][i].second;

		for(int d=0; d<4; d++){
			int nr = r + dr[d];
			int nc = c + dc[d];

			if(nr<0 || nr>N-1 || nc<0 || nc>M-1) continue;
			if(board[nr][nc] != 0) continue;

			DFS(r,c,d,0,isnum1, isnum2);
		}
	}

}

void FindDistance() {
	for(int i=1; i<area_num; i++){
		for(int j=i+1; j<area_num; j++){
			MakeBridge(i,j);

			if(dist[i][j] == INF) continue;
			
			bridge_list.push_back(make_pair(make_pair(i,j),dist[i][j]));
		}
	}

}

bool CheckAllConnected() {
	memset(connect, false, sizeof(connect));
	memset(connect_island, false, sizeof(connect_island));

	for(int i=0; i<bridge_list.size(); i++){
		if(comb[i]) {
			int isnum1 = bridge_list[i].first.first;
			int isnum2 = bridge_list[i].first.second;
			connect[isnum1][isnum2] = true;
			connect[isnum2][isnum1] = true;
		}
	}

	queue<int> q;
	q.push(1);
	connect_island[1] = true;
	
	int island_cnt = 1;

	while(!q.empty()) {
		int cur = q.front();
		q.pop(); 

		if(island_cnt == area_num-1) {
			return true;
		}
		
		for(int i=1; i<area_num; i++){
			if(cur == i) continue;
			if(!connect[cur][i] || connect_island[i]) continue;

			q.push(i);
			connect_island[i] = true;
			island_cnt++;
		}
	}

	return false;
}

void DistDFS(int idx, int cnt, int sum) {
	if(cnt >= 1) {
		if(CheckAllConnected()) {
			ans = min(ans, sum);
		}
	}

	for(int i=idx; i<bridge_list.size(); i++) {
		if(comb[i] == true) continue;

		comb[i]=true;
		DistDFS(i, cnt+1, sum + bridge_list[i].second);
		comb[i] = false;
	}
}


int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> board[i][j];

			if(board[i][j] == 1) {
				v.push_back(make_pair(i,j));
			}
		}
	}

	MakeLabels();

	for(int i=0;i<ISLAND_MAX;i++){
		for(int j=0; j<ISLAND_MAX; j++){
			dist[i][j] = INF;
		}
	}

	FindDistance();

	DistDFS(0,0,0);

	if(ans == INF) cout << "-1";
	else cout << ans;



	return 0;
}
