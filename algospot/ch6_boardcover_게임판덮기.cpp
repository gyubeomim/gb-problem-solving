#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

// 주어진 칸을 덮을 수 있는 네가지 방법
// 블록을 구성하는 세 칸의 상대적인 위치 (dy,dx) 목록 (그림 6.3 참조)
const int coverType[4][3][2] = {
	{ {0 ,0}, {1, 0}, {0, 1} },   // (b)
	{ {0 ,0}, {0, 1}, {1, 1} },   // (c)
	{ {0 ,0}, {1, 0}, {1, 1} },   // (d)
	{ {0 ,0}, {1, 0}, {1, -1} }   // (e)
};	

// board의 (y,x)를 type번 방법으로 덮거나, 덮었던 블록을 없앤다
// delta = 1이면 덮고 -1이면 덮었던 블록을 없앤다
// 만약 블록이 제대로 덮이지 않은 경우 (게임판 밖으로 나가거나, 겹치거나 검은 칸을 덮을 때) false를 반환한다
bool myset(vector<vector<int>>& board, int y, int x, int type, int delta) {
	bool ok = true;

	for(int i=0;i<3;i++){
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if(ny<0 || ny>=board.size() || nx<0 || nx>=board[0].size()) { ok = false; }
		else if ((board[ny][nx] += delta) > 1) { ok = false; }
	}
	return ok;
}

// board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다
// board[i][j] = 1 이미 덮인 칸 혹은 검은 칸
// board[i][j] = 0 아직 덮이지 않은 칸
int cover(vector<vector<int>>& board){
	// 아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다
	int y=-1, x=-1;

	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[i].size(); j++){
			if(board[i][j] == 0) {
				y = i; 
				x = j;
				break;
			}
		}
		if(y != -1) break;
	}
		
	// 기저 사례: 모든 칸을 채웠으면 1을 반환한다
	if(y == -1) return 1;

	int ret = 0;
	for(int type=0; type<4; type++){
		// 만약 board[y][x]를 type 형태로 덮을 수 있다면 재귀 호출한다
		if( myset(board, y, x, type, 1) ) { 
			ret += cover(board); 
		}
		// 덮었던 블록을 치운다
		myset(board, y, x, type, -1);
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T); 

	while(T--) {
		int H, W;
		scanf("%d %d", &H, &W);

		vector<vector<int>> board(H, vector<int>(W, 0));
		int whiteCount = 0;

		// 문자열 한 줄을 받을 때 W(<=20)보다 약간 여유를 두는 것이 좋음
		// 예) char row[60];
		for(int i = 0; i < H; i++){
			char row[60];
			scanf("%s", row);

			for(int j = 0; j < W; j++){
				if(row[j] == '#') {
					board[i][j] = 1; // 검은 칸
				} else {
					board[i][j] = 0; // 흰 칸
					whiteCount++;
				}
			}
		}

		// 흰 칸 수가 3의 배수가 아니면 덮을 수 없다
		if(whiteCount % 3 != 0){
			printf("%d\n", 0);
		} 
		else {
			printf("%d\n", cover(board));
		}
	}
}

