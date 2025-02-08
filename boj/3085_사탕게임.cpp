#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM=55;
int N;
char board[LM][LM];
int ans=1;

void searchByRow(char tboard[][LM], int row, int col1, int col2) {
	int tans = 1;
	for(int c=0; c<N-1; c++) {
		if(tboard[row][c] == tboard[row][c+1]){
			tans++;
			if(tans > ans) ans = tans;
		}
		else tans = 1;
	}

	tans=1;
	for(int r=0; r<N-1; r++) {
		if(tboard[r][col1] == tboard[r+1][col1]) {
			tans++;
			if(tans > ans) ans = tans;
		}
		else tans = 1;
	}

	tans=1;
	for(int r=0; r<N-1; r++) {
		if(tboard[r][col2] == tboard[r+1][col2]) {
			tans++;
			if(tans > ans) ans = tans;
		}
		else tans = 1;
	}

}

void searchByCol(char tboard[][LM], int col, int row1, int row2) {
	int tans = 1;
	for(int r=0; r<N-1; r++) {
		if(tboard[r][col] == tboard[r+1][col]) {
			tans++;
			if(tans > ans) ans = tans;
		} else tans = 1;
	}

	tans=1;
	for(int c=0; c<N-1; c++) {
		if(tboard[row1][c] == tboard[row1][c+1]) {
			tans++;
			if(tans > ans) ans = tans;
		} else tans = 1;
	}

	tans=1;
	for(int c=0; c<N-1; c++) {
		if(tboard[row2][c] == tboard[row2][c+1]) {
			tans++;
			if(tans > ans) ans = tans;
		} else tans = 1;
	}

}

void search() {
	for(int r=0; r<N; r++){
		for(int c=0; c<N-1; c++) {
			char tboard[LM][LM];
			memcpy(tboard, board, sizeof(board));
		
			char temp = tboard[r][c];
			tboard[r][c] = tboard[r][c+1];
			tboard[r][c+1] = temp;

			searchByRow(tboard, r, c, c+1);
		}
	}

	for(int c=0; c<N; c++){
		for(int r=0; r<N-1; r++) {
			char tboard[LM][LM];
			memcpy(tboard, board, sizeof(board));
			
			char temp = tboard[r][c];
			tboard[r][c] = tboard[r+1][c];
			tboard[r+1][c] = temp;

			searchByCol(tboard, c, r, r+1);
		}
	}
}

int main(int argc, char **argv){
	scanf("%d", &N);

	for(int r=0;r<N;r++){
		for(int c=0; c<N; c++){
			scanf(" %1c", &board[r][c]);
		}
	}

	search();
	printf("%d", ans);
}
