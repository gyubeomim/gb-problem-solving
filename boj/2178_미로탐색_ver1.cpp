#include <cstdio>
#include <queue>

using namespace std;

constexpr int LM=105;

const int dr[]={-1,1,0,0};
const int dc[]={0,0,1,-1};

int N,M;
int Map[LM][LM];
int visited[LM][LM];

struct Data {
	int r,c;
	int depth;
};

queue<Data> que;

void BFS() {
	que.push({ 0, 0, 1 });
	visited[0][0]=1;

	while(!que.empty()) {
		Data t = que.front();
		que.pop();

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
			que.push({ nr, nc, t.depth+1 });
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
