#include <bits/stdc++.h>
using namespace std;

// 대각선의 방향: 왼쪽 아래로 내려가는 대각선, 오른쪽 아래로 내려가는 대각선
const int dx[2]={-1,1};
const int dy[2]={1,1};

vector<string> board;

int id[2][8][8];  // id[dir][x][y]=dir 방향 대각선을 따라 인접한 빈 칸 묶음들 중 (y,x)가 속한 묶음의 번호

int N,M;
int adj[64][64];

vector<int> aMatch, bMatch;
vector<bool> visited;

int dfs(int a){
	if(visited[a]) return false;
	visited[a] = true;
	for(int b=0; b<M;b++){
		if(adj[a][b]){
			if(bMatch[b] == -1 || dfs(bMatch[b])){
				aMatch[a]=b;
				bMatch[b]=a;
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatch(){
	aMatch = vector<int>(N, -1);
	bMatch = vector<int>(M, -1);
	int size=0;
	for(int start=0; start<N; start++){
		visited = vector<bool>(N, false);
		if(dfs(start)) ++size;
	}
	return size;
}

int placeBishops(){
	// 각 묶음에 번호를 붙인다
	memset(id,-1,sizeof(id));

	int count[2] = {0,0};
	for(int dir=0; dir<2; dir++){
		for(int y=0; y<board.size(); y++){
			for(int x=0; x<board.size(); x++){
				if(board[y][x]=='.' && id[dir][y][x] == -1) {
					int cy=y;
					int cx=x;
					while(0<=cy && cy < board.size() 
								&& 0<=cx && cx < board.size()
								&& board[cy][cx] == '.'){
									id[dir][cy][cx] = count[dir];
									cy += dy[dir];
									cx += dx[dir];
								}
					count[dir]++;
				}
			}
		}
	}

	// 이분 그래프를 만든다
	N = count[0];
	M = count[1];
	memset(adj,0,sizeof(adj));
	for(int y=0; y<board.size(); y++){
		for(int x=0; x<board.size(); x++){
			if(board[y][x] == '.'){
				adj[id[0][y][x]][id[1][y][x]] = 1;
			}
		}
	}

	return bipartiteMatch();
}

int main(int argc, char **argv) {
	//freopen("s_in_1221.txt", "r", stdin);
  int C;
  scanf("%d", &C);
  while (C--) {
    scanf("%d", &N);

    board.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> board[i];
    }

		int ans = placeBishops();
    printf("%d\n", ans);
  }
}
