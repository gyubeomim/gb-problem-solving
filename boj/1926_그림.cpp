#include <bits/stdc++.h>
#include <ctime>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int LM = 502;

int board[LM][LM];
bool vis[LM][LM];

int N,M;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int mx=0;  // 그림의 최대값
int num=0; // 그림의 수

void bfs() {
	for(int i=0; i<N; i++){
		for(int j=0;j<M;j++){
			if(board[i][j] == 0 || vis[i][j]) continue;
			num++;

			queue<pii> Q;
			vis[i][j] = 1;
			Q.push({i,j});

			int area=0;
			while(!Q.empty()){
				area++;
				pii cur = Q.front(); Q.pop();
				for(int d=0;d<4;d++){
					int nx = cur.X + dx[d];
					int ny = cur.Y + dy[d];

					if(nx<0||nx>=N||ny<0||ny>=M) continue;
					if(vis[nx][ny] || board[nx][ny]!=1) continue;
					
					vis[nx][ny] = 1;
					Q.push({nx,ny});
				}
			}
			mx = max(mx, area);
		}
	}
}

int main(int argc, char **argv){
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				scanf("%d",&board[i][j]);
			}
		}


		bfs();
		printf("%d\n%d\n", num, mx);
}
