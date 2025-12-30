#include <bits/stdc++.h>

using namespace std;

int ladder[31][11];
int N,M,H; 

bool IsAnswer() {

	for(int c=1; c<N; c++) {
		int col = c;
		for(int r=1; r<=H; r++){
			if(ladder[r][col]) col++;
			else if(ladder[r][col-1]) col--;
		}

		if(col != c) {
			return false;
		}
	}

	return true;
}

void dfs(int max_depth, int cnt) {
	if(max_depth == cnt) {
		if(IsAnswer()) {
			cout << max_depth;
			exit(0);
		}
		return;
	}

	for(int c=1; c<N; c++) {
		for(int r=1; r<=H; r++){
			if(ladder[r][c] || ladder[r][c-1] || ladder[r][c+1]) continue;
			
			ladder[r][c] = 1;
			dfs(max_depth, cnt+1);
			ladder[r][c] = 0;
			
			while(!ladder[r][c-1] && !ladder[r][c+1]) r++;
		}
	}

	return;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	cin >> N>>M>>H;

	for(int i=1; i<=M; i++){
		int r,c;
		cin >> r >> c;

		ladder[r][c] = 1;
	}

	for(int i=0; i<4; i++){
		dfs(i, 0);
	}

	cout << -1;
	 

	return 0;
}
