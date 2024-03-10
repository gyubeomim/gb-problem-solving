#include <cstdio>
#include <cstring>

#define rnt register int
constexpr int LM = 55;

int Map[LM][LM];
int visited[LM][LM];
int vcnt=0;

int fr,re;

struct Data {
	int r,c,depth;
} que[LM*LM];

int R,C;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int ans=0;

void BFS(int r, int c) {
	fr=re=0;
	que[re++] = { r, c, 0 };
	visited[r][c] = ++vcnt;
	
	while(fr < re) {
		Data t = que[fr++];

		for(int i=0; i<4; i++) {
			int nr = t.r + dr[i];
			int nc = t.c + dc[i];

			if(nr<0 || nr>R-1 || nc<0 || nc>C-1) continue;
			if(Map[nr][nc] == 0) continue;
			if(visited[nr][nc] == vcnt) continue;

			visited[nr][nc] = vcnt;
			que[re++] = { nr, nc, t.depth+1 };
		}
	}

	if(ans < que[re-1].depth) ans = que[re-1].depth;
}

int main(int argc, char **argv){
	scanf("%d %d", &R, &C);

	for(int r=0; r<R;r++){
		for(int c=0; c<C;c++){
			char ch;
			scanf(" %c", &ch);

			if(ch == 'W') Map[r][c] = 0;
			else if(ch == 'L') Map[r][c] = 1;
		}
	}

	for(int r=0; r<R;r++){
		for(int c=0; c<C;c++){
			if(Map[r][c] != 0) 
				BFS(r,c);
		}
	}
	
	printf("%d", ans);


	return 0;
}
