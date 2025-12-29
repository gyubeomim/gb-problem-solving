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

enum DIR { E_=1, W_=2, S_=3, N_=4, INVALID=-1000 };

int turn(int from, int to){
	if(from == to) return 0;
	if((from==E_ && to==W_) || (from==W_ && to == E_) ||
			(from==S_ && to==N_) || (from==N_ && to==S_)) {
				return 2;
	}
	return 1;
}

int M,N;
int board[LM][LM];

int sr,sc,sd;
int er,ec,ed;

struct Data{
	int r,c,d, step;
} que[LM*LM*4];

int fr,re;
int visited[LM][LM][5];

constexpr int dr[] = {0, 0,0,1,-1};  // E, W, S, N (from index 1)
constexpr int dc[] = {0, 1,-1,0,0};

void bfs(){
	fr=re=0;

	que[re++] = {sr, sc, sd, 0};
	visited[sr][sc][sd] = 1;

	while(fr < re){
		auto [r,c,d,step] = que[fr++];

		if(r == er && c == ec && d == ed){
			printf("%d\n", step); return;
		}

		// TURN
		for(int nd=1; nd<=4; nd++){
			if(turn(d,nd) == 2) continue;
			if(visited[r][c][nd]) continue;
			que[re++] = {r,c,nd,step + turn(d, nd)};
			visited[r][c][nd] = 1;
		}


		// GO
		for(int i=1; i<=3; i++){
			int nr = r + dr[d] * i;
			int nc = c + dc[d] * i;
			if(nr<1 || nr>M || nc<1 || nc>N) break;
			if(board[nr][nc] == 1) break;
			if(visited[nr][nc][d]) continue;

			que[re++] = {nr, nc, d, step+1 };
			visited[nr][nc][d] = 1;
		}
	}
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1006.txt", "r", stdin);
	#endif

	scanf("%d%d", &M, &N);
	for(int r=1; r<=M; r++){
		for(int c=1; c<=N; c++){
			scanf(" %d", &board[r][c]);
		}
	}

	scanf("%d%d%d", &sr,&sc,&sd);
	scanf("%d%d%d", &er,&ec,&ed);

	bfs();
}