#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

constexpr int LM = 105;
constexpr int INF = 0x3f3f3f3f;
using Node = pair<int, pii>;

int N;
int gx, gy;
int board[LM][LM];

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

int dijkstra(int x, int y){
	static int dist[LM][LM];
	for(int i=0; i<=N+1; i++) 
		for(int j=0; j<=N+1; j++) 
			dist[i][j] = INF;
	
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	dist[x][y] = 0;
	pq.push({0, {x, y}});

	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		int cost = cur.X;
		int cx = cur.Y.X;
		int cy = cur.Y.Y;

		if(cost != dist[cx][cy]) continue;  // 이미 더 낮은 비용으로 갱신된 경우 skip

		if(cx==gx && cy==gy){
			return cost;
		}

		for(int d=0; d<4; d++){
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if(nx<1 || nx>N || ny<1 || ny>N) continue;

			int add = 0;
			if(board[nx][ny] > board[cx][cy]) add = (board[nx][ny]-board[cx][cy])*(board[nx][ny]-board[cx][cy]);
			if(board[nx][ny] < board[cx][cy]) add = board[cx][cy] - board[nx][ny];

			int ndist = cost + add;
			if(ndist < dist[nx][ny]){
				dist[nx][ny] = ndist;
				pq.push({ndist, {nx, ny}});
			}
		}
	}
	return INF;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d2929.txt", "r", stdin);
	#endif

	scanf("%d", &N);
	scanf("%d%d", &gx, &gy);

	memset(board, 0 , sizeof(board));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf(" %d", &board[i][j]);
		}
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i=0; i<=N+1; i++){
		  int a;
			a = dijkstra(i,0);  // dist
			pq.push(a);
			a = dijkstra(i,N+1);
			pq.push(a);
	}
	for(int j=1; j<=N; j++){
		  int a;
			a = dijkstra(0,j);  // dist
			pq.push(a);
			a = dijkstra(N+1,j);
			pq.push(a);
	}

	int ans = pq.top(); pq.pop();
	printf("%d\n", ans);
}