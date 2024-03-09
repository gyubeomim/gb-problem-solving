#include <cstdio>
#include <cstring>

constexpr int LM=55;
int Map[LM][LM];
int visited[LM][LM];

int W,H;
int vcnt=0;

int fr,re; 

struct Data{
	int r,c;
} que[LM*LM];

const int dr[] = {-1,1,0,0, -1, -1, 1, 1};
const int dc[] = {0,0,-1,1, -1, 1, -1, 1};

int ans = 0;

void BFS(int r, int c) {
	fr=re=0;

	que[re++] = { r,c };
	visited[r][c] = 1;

	while(fr < re) {
		Data t = que[fr++];

		for(int i=0;i<8;i++){
			int nr = t.r+dr[i];
			int nc = t.c+dc[i];

			if(nr < 0 || nr>H-1 || nc < 0 || nc > W-1) continue;
			if(visited[nr][nc]) continue;
			if(Map[nr][nc] == 0) continue;

			visited[nr][nc] = 1;
			que[re++] = { nr, nc };
		}

	}
}


int main(int argc, char **argv){

	while(true) {
		ans = 0;
		memset(visited, 0, sizeof(visited));
		memset(Map, 0, sizeof(Map));

		scanf("%d %d", &W, &H);

		if(W==0 && H==0) return 0;

		for(int i=0; i<H;i++){
			for(int j=0; j<W; j++) {
				int val;
				scanf("%d", &val);
				Map[i][j] = val;
			}
		}

		for(int i=0; i<H;i++){
			for(int j=0; j<W; j++) {
				if(Map[i][j] == 1 && !visited[i][j]) {
					ans++;
					BFS(i,j);
				}
			}
		}

		printf("%d\n", ans);

	}

	return 0;
}
