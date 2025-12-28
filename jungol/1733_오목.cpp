#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 19;

int board[LM][LM];
const int dr[] = {0,1,1,-1};
const int dc[] = {1,0,1,1};

inline bool in(int r, int c) { return 0<=r && r<LM && 0<=c && c<LM; }

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d5757.txt", "r", stdin);
	#endif

	for(int i=0;i<19;i++){
		for(int j=0;j<19;j++){
			scanf(" %d",&board[i][j]);
		}
	}

	for(int r=0;r<19;r++){
		for(int c=0;c<19;c++){
			int v= board[r][c];
			if(v==0)continue;

			for(int d=0; d<4; d++){
				int pr = r-dr[d];
				int pc = c-dc[d];
				if(in(pr, pc) && board[pr][pc]==v) continue;  // not a start

				int cnt = 1;
				int nr = r+dr[d];
				int nc = c+dc[d];
				while(in(nr,nc) && board[nr][nc] == v){
					cnt++;
					nr += dr[d];
					nc += dc[d];
				}

				if(cnt == 5){
					if(in(nr, nc) && board[nr][nc] == v) continue;   // no 6목
					printf("%d\n%d %d\n", v, r+1, c+1);
					return 0;
				}
			}
		}
	}
	printf("0\n");
}