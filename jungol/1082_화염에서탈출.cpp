#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

enum{
	LM=55,
	QLM=LM*LM,
	INF=1<<20
};
int R,C;
int timeTable[LM][LM];

int sr, sc;
int er, ec;

struct Data {
	int r,c,lev;
} que[QLM];
int fr, re;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

void push(int r, int c, int lev){
	if(timeTable[r][c] <= lev) return;
	timeTable[r][c] = lev;
	que[re++] = { r, c, lev };
}

void input() {
	scanf("%d%d",&R,&C);
	int i,j;
	char ch;
	for(i=1; i<=R; i++){
		for(j=1; j<=C; j++){
			scanf(" %c", &ch);
			timeTable[i][j] = INF;
			if(ch=='X') timeTable[i][j] = 0;
			else if(ch=='S') { sr = i, sc = j; }
			else if(ch=='D') {
				timeTable[i][j] = 0;
				er = i, ec = j;
			}
			else if(ch == '*') push(i,j,0);
		}
	}
}

void bfs(){
	while(fr<re){
		Data t = que[fr++];
		for(int i=0; i<4; i++){
			push(t.r+dr[i], t.c+dc[i], t.lev+1);
		}
	}
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d.txt", "r", stdin);
	#endif

	input();
	bfs();

	timeTable[er][ec] = INF;
	fr = re = 0;
	push(sr, sc, 0);
	bfs();

	if(timeTable[er][ec] == INF) puts("impossible");
	else printf("%d\n", timeTable[er][ec]);
}