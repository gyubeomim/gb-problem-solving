#include <bits/stdc++.h>
using namespace std;

/*
0  1  2  3  4 
5  6  7  8  9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24
*/

char cache[1<<25+1];
vector<int> moves;
int state;

inline int cell(int y, int x) { return 1<<(y*5 + x); }

//게임판에 놓을 수 있는 블록들의 위치를 미리 계산한다
void precalc(){
	// 세 칸짜리 L자로 모양 블록들을 계산한다
	for(int y=0; y<4; y++){
		for(int x=0; x<4; x++){
			vector<int> cells;
			for(int dy=0; dy<2; dy++){
				for(int dx=0; dx<2; dx++){
					cells.push_back(cell(y+dy, x+dx));
				}
			}
			int square = cells[0]+cells[1]+cells[2]+cells[3];
			for(int i=0;i<4;i++)
				moves.push_back(square - cells[i]);
		}
	}

	// 두 칸짜리 블록들을 계산한다
	for(int i=0; i<5; i++){
		for(int j=0; j<4; j++){
			moves.push_back(cell(i,j) + cell(i,j+1));
			moves.push_back(cell(j,i) + cell(j+1,i));
		}
	}
}


// 현재 게임판 상태가 board일 때 현재 차례인 사람이 승리할지 여부를 판단한다
// (y,x) 칸에 블록이 있다. <==> (y*5+x)번 비트가 켜져있다.
char play(int board){
	char& ret = cache[board];
	if(ret != -1) return ret;
	ret = 0;

	// 모든 수를 고려한다
	for(int i=0; i<moves.size(); i++){
		// 이 수를 이 게임판에 놓을 수 있는가 확인
		if((moves[i] & board) == 0) {
			if(play(board | moves[i]) == 0) {
				ret = 1;
				break;
			}
		}
	}
	return ret;
}


int main(int argc, char **argv){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	// freopen("data/d1991.txt", "r", stdin);
#endif
	// int C; scanf("%d",&C);
	int C; cin >> C;

	precalc();
	while(C--) {
		state = 0;
		memset(cache, -1, sizeof(cache));	
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				// char t; scanf("%c", &t);
				char t; cin >> t;
				if(t == '#') state += cell(i,j);
			}
		}
		if(play(state)) cout << "WINNING\n";
		else cout << "LOSING\n";
	}
}