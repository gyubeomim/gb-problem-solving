#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

constexpr int LM = 1005;
char farm[LM][LM];
int visited[LM][LM];
int W,H;

struct Data{
 int w,h;
} que[LM*LM];
int fr, re;

const int dw[] = {-1,1,0,0};
const int dh[] = {0,0,-1,1};

int bfs(int w, int h){
	if(farm[w][h] == '.' || visited[w][h]) return 0;
	
	que[re++] = {w,h};
	visited[w][h] = true;
	
	int ret = 0;
	while(fr < re){
		Data cur = que[fr++];
		ret++;

		for(int d=0; d<4; d++){
			int nw = cur.w + dw[d];
			int nh = cur.h + dh[d];
			if(nw < 0 || nw > W-1 || nh < 0 || nh > H-1) continue;
			if(visited[nw][nh]) continue;
			if(farm[nw][nh] == '.') continue;

			que[re++] = {nw, nh};
			visited[nw][nh] = 1;
		}
	}
	return ret;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d3333.txt", "r", stdin);
	#endif

	scanf("%d%d", &W, &H);
	for(int h=0; h<H; h++){
		for(int w=0; w<W; w++){
			char c; scanf(" %1c", &c);
			farm[w][h] = c;
		}
	}

	int ans = -1;
	for(int h=0; h<H; h++){
		for(int w=0; w<W; w++){
			if(!visited[w][h]){
				ans = max(ans, bfs(w,h));
			}
		}
	}
	printf("%d\n", ans);
}