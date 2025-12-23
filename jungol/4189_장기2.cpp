#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

constexpr int LM = 1005;

const int dr[] = { 2,2, -2, -2, -1, 1, -1, 1};
const int dc[] = {-1,1, -1,  1,  2, 2, -2, -2};

int visited[LM][LM];
int sr, sc;
int tr, tc;
int N,M;

struct Data{
	int r,c,step;
};

Data que[LM*LM];
int fr, re;

int bfs(int r, int c){
	que[re++] = {r, c, 0};
	visited[r][c] = 1;

	while(fr<re) {
		Data d = que[fr++];

		if(d.r == tr && d.c == tc){
			return d.step;
		}

		for(int i=0; i<8; i++){
			int nr = d.r + dr[i];
			int nc = d.c + dc[i];
			if(nr <= 0 || nr > N || nc <= 0 || nc > M) continue;
			if(visited[nr][nc]) continue;

			que[re++] = {nr, nc, d.step+1};
			visited[nr][nc] = 1;
		}
	}
	return -1;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d8888.txt", "r", stdin);
	#endif

	scanf("%d%d", &N, &M);
	scanf("%d%d%d%d", &sr, &sc, &tr, &tc);

	int ans = bfs(sr, sc);
	printf("%d\n", ans);
}