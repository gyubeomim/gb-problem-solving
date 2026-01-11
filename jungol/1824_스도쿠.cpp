#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int board[9][9];
int row[9][10];
int col[9][10];
int box[9][10];

vector<pii> empties;

int getBoxIndex(int r, int c){
	return (r/3)*3 + c/3;
}

bool dfs(int idx){
	if(idx == empties.size()) return true;

	int r = empties[idx].X;
	int c = empties[idx].Y;
	int b = getBoxIndex(r,c);

	for(int n=1; n<=9; n++){
		if(!row[r][n] && !col[c][n] && !box[b][n]){
			board[r][c] = n;
			row[r][n] = 1;
			col[c][n] = 1;
			box[b][n] = 1;

			if(dfs(idx+1)) return true;

			board[r][c] = 0;
			row[r][n] = 0;
			col[c][n] = 0;
			box[b][n] = 0;
		}
	}
	return false;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1824.txt", "r", stdin);
	#endif

	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf(" %d", &board[i][j]);
			int &val = board[i][j];
			int b = getBoxIndex(i,j);
			if(val != 0){
				row[i][val] = 1;
				col[j][val] = 1;
				box[b][val] = 1;
			}else{
				empties.push_back({i,j});
			}
		}
	}

	dfs(0);

	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			printf("%d ", board[i][j]);
		}
		puts("");
	}
}