#include <bits/stdc++.h>

using namespace std;
int N;
int board[17][17] = {0};
int result=0;
enum BarStatus {
	HORIZONTAL = 1,
	INCLIEND = 2,
	VERTICAL = 3,
};

struct Bar {
	int status;
};

bool IsValid(int x, int y){
	if(board[x][y] == 1 || x < 1 || x > N || y < 1 || y > N) {
		return false;
	}
	return true;
}


void dfs(Bar b, int cx, int cy){
	if(cx == N && cy == N){
		result++;
		return; 
	}
	
	switch(b.status){
		case HORIZONTAL:
			if(IsValid(cx, cy+1)) {
				// cout << "HOR -> HOR: " << cx << ", " << cy << endl;
				b.status = HORIZONTAL;
				dfs(b, cx, cy+1);
			}
			if(IsValid(cx+1, cy) && IsValid(cx, cy+1) && IsValid(cx+1, cy+1)) {
				// cout << "HOR -> INC: " << cx << ", " << cy << endl;
				b.status = INCLIEND;
				dfs(b, cx+1, cy+1);
			}

			break;
		case INCLIEND:
			if(IsValid(cx, cy+1)) {
				b.status = HORIZONTAL;
				dfs(b, cx, cy+1);
			}
			if(IsValid(cx+1, cy)) {
				b.status = VERTICAL;
				dfs(b, cx+1, cy);
			}
			if(IsValid(cx+1, cy) && IsValid(cx, cy+1) && IsValid(cx+1, cy+1)) {
				b.status = INCLIEND;
				dfs(b, cx+1, cy+1);
			}

			break;
		case VERTICAL:
			if(IsValid(cx+1, cy)) {
				b.status = VERTICAL;
				dfs(b, cx+1, cy);
			}
			if(IsValid(cx+1, cy) && IsValid(cx, cy+1) && IsValid(cx+1, cy+1)) {
				b.status = INCLIEND;
				dfs(b, cx+1, cy+1);
			}
			break;
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N;j ++){
			cin >> board[i][j];
		}
	}

	Bar b;
	b.status = HORIZONTAL;

	dfs(b,1,2);
	
	cout << result;

	return 0;
}
