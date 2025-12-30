#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 105;

int R,C;
int tR, tC;
int Map[LM][LM];
int visited[LM][LM];


struct Data{
	int r, c, t;
} que[LM*LM];

int fr,re;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int ans = 0;
int num_zerg=0;

void BFS(int r, int c) {
	fr=re=0;
	memset(visited, 0, sizeof(visited));

	que[re++] = { r, c, 3 };
	visited[r][c] = 1;

	while(fr < re) {
		Data d = que[fr++];

		num_zerg--;

		for(int i=0;i<4;i++){
			int nr = d.r + dr[i];
			int nc = d.c + dc[i];

			if(nr<0 || nr>R || nc<0 || nc>C) continue;
			if(visited[nr][nc]) continue;
			if(Map[nr][nc] == 0) continue;

			visited[nr][nc] = 1;
			que[re++] = { nr, nc, d.t+1 };
		}
	}

	if(ans < que[re-1].t) ans = que[re-1].t;
}

int main(int argc, char **argv){
	scanf("%d %d", &C, &R);

	for(int r=1; r<=R; r++){
		for(int c=1; c<=C; c++){
			scanf("%1d", Map[r]+c);
			if(Map[r][c]==1) {
				num_zerg++;
			}
		}
	}

	scanf("%d %d", &tC, &tR);
	BFS(tR, tC);
	
	printf("%d\n%d", ans, num_zerg);


	return 0;
}
