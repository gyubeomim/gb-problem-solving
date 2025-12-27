#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

constexpr int LM = 19;

struct Data{
 int r,c,d1,d2,d3,d4,ar, ac;
};

Data que[LM*LM];
int visited[LM][LM];
int fr,re;

int board[LM][LM];

constexpr int dr[] = {-1,1,0,0,-1,1,1,-1};
constexpr int dc[] = {0,0,-1,1,-1,1,-1,1};

bool bfs(int r, int c, int v){
	que[re++] = {r,c,1,1,1,1,r,c};
	visited[r][c] = 1;

	while(fr < re){
		Data cur = que[fr++];

		if(cur.d1 == 5 || cur.d2 == 5 || cur.d3 == 5 || cur.d4 == 5){
				printf("%d\n%d %d\n", board[cur.r][cur.c], cur.ar, cur.ac);
				return true;
		}

		for(int d=0; d<8; d++){
				int nr = cur.r + dr[d];
				int nc = cur.c + dc[d];
				if(nr < 0 || nr>LM-1 || nc<0 || nc>LM-1) continue;
				if(board[nr][nc] == 0 || board[nr][nc] != v) continue;
				if(visited[nr][nc]) continue;

				visited[nr][nc] = 1;

				int nar = nr < cur.r ? nr : cur.r;
				int nac = nc < cur.c ? nc : cur.c;

				// d1 : |
				// d2 : /
				// d3 : -
				// d4 : 

				if(( cur.r < nr && cur.c < nc ) || ( cur.r > nr && cur.c > nc ) ) 
					que[re++] = {nr, nc, cur.d1, cur.d2, cur.d3, cur.d4+1, nar, nac};

				else if(( cur.r < nr && cur.c == nc ) || ( cur.r > nr && cur.c == nc ) ) 
					que[re++] = {nr, nc, cur.d1, cur.d2, cur.d3+1, cur.d4, nar, nac};

				else if(( cur.r == nr && cur.c < nc ) || ( cur.r == nr && cur.c > nc ) ) 
					que[re++] = {nr, nc, cur.d1+1, cur.d2, cur.d3, cur.d4, nar, nac};

				else if(( cur.r > nr && cur.c < nc ) || ( cur.r < nr && cur.c > nc ) ) 
					que[re++] = {nr, nc, cur.d1, cur.d2+1, cur.d3, cur.d4, nar, nac};
		}
	}
	return false;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d5757.txt", "r", stdin);
	#endif

	for(int i=0;i<19;i++){
		for(int j=0;j<19;j++){
			scanf(" %d",&board[i][j]);
		}
	}

	printf("BORAD is\n");
	for(int i=0;i<19;i++){
		for(int j=0;j<19;j++){
			printf("%d ", board[i][j]);
		}
		puts("");
	}

	for(int i=0;i<19;i++){
		for(int j=0;j<19;j++){
			if(board[i][j] != 0 && !visited[i][j]){
				if(bfs(i,j,1)){
					break;
				}
				if(bfs(i,j,2)){
					break;
				}
			}
		}
	}

}