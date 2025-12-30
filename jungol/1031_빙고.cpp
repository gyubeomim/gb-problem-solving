#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 7;

int board[LM][LM];

bool check(int n){
	bool found=false;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(board[i][j] == n){
				board[i][j] = -1;
				found = true;
				break;
			}
		}
		if(found) break;
	}

	int found_bingo = 0;

	for(int r=0; r<5; r++){
		if(board[r][0] == -1 
				&& board[r][1] == -1
				&& board[r][2] == -1
				&& board[r][3] == -1
				&& board[r][4] == -1){
					found_bingo++;
				}
	}

	for(int c=0; c<5; c++){
		if(board[0][c] == -1 
				&& board[1][c] == -1
				&& board[2][c] == -1
				&& board[3][c] == -1
				&& board[4][c] == -1){
					found_bingo++;
				}
	}

	if(board[0][0] == -1
		&& board[1][1] == -1
		&& board[2][2] == -1
		&& board[3][3] == -1
		&& board[4][4] == -1){
			found_bingo++;
		}

	if(board[0][4] == -1
		&& board[1][3] == -1
		&& board[2][2] == -1
		&& board[3][1] == -1
		&& board[4][0] == -1) {
			found_bingo++;
		}

	return found_bingo >= 3 ? true : false;
}


int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1031.txt", "r", stdin);
	#endif
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			scanf(" %d", &board[i][j]);
		}
	}

	int ans = 0;
	bool found = false;

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			int num; scanf("%d", &num);
			ans++;
			if(check(num)) {
				found = true;
				printf("%d\n", ans);
				break;
			}
		}
		if(found) break;
	}

}