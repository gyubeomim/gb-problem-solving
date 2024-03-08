#include <cstdio>

constexpr int LM=105;
constexpr int NLM=LM*LM;

const int dr[]={-1,1,0,0};
const int dc[]={0,0,1,-1};

int N,M;
int Map[LM][LM];
int visited[LM][LM];

int fr,re;    // front, end

struct Data {
	int r,c;
	int depth;
} que[NLM]; // queue

void BFS() {
	fr=re=0;

	que[re++] = { 0, 0, 1 };
	visited[0][0]=1;

	while(fr < re) {
		Data t = que[fr++];

		if(t.r == N-1 && t.c == M-1) {
			printf("%d\n", t.depth);
			return;
		}

		for(int i=0;i<4;i++){
			int nr = t.r+dr[i];
			int nc = t.c+dc[i];

			if(nr<0 || nr>N-1 || nc<0 || nc>M-1) continue;
			if(Map[nr][nc]==0) continue;
			if(visited[nr][nc]) continue;

			visited[nr][nc] = 1;
			que[re++] = { nr, nc, t.depth+1 };
		}
	}
}

int main(int argc, char **argv){
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d", Map[i]+j);
		}
	}

	BFS();

	return 0;
}
