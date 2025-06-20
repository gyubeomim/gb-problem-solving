#include <bits/stdc++.h>
using namespace std;

const int LM = 405;

// 기지의 지도
int H,W;
int id[LM][LM];  
vector<string> board;

int N,M;                  // Number of vertices in A, B group
int adj[LM][LM];

// 각 정점에 매칭된 상대 정점의 번호를 저장한다. 매칭되지 않은 경우 -1
vector<int> aMatch, bMatch;
// aChosen[i] = 최대 독립 집합에 Ai가 포함되는가?
// bChosen[i] = 최대 독립 집합에 Bi가 포함되는가?
vector<bool> aChosen, bChosen;
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

void bipartiteMatch(){
	aMatch = vector<int>(N, -1);
	bMatch = vector<int>(M, -1);
	for(int start=0; start<N; start++){
		visited = vector<bool>(N, false);
		dfs(start);
	}
}

// 이분 그래프의 정보가 주어질 때 실제 최대독립집합을 계산한다
void calcMaxIndependentSet(){
	// aMatch, bMatch를 계산한다
	bipartiteMatch();

	// 1. A의 모든 정점들을 선택하고 B에서 대응되지 않는 정점들을 선택한다
	aChosen = vector<bool>(N, true);
	bChosen = vector<bool>(M, false);
	for(int i=0; i<M; i++){
		if(bMatch[i] == -1) {
			bChosen[i] = true;
		}
	}
	// 2. 두 정점이 연결되어 있을 경우, 그 중 A의 정점을 지우고 B의 대응된 정점을 대신 선택한다.
	// 더 이상 변화가 일어나지 않을 때까지 반복
	while(true){
		bool changed = false;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(aChosen[i] && bChosen[j] && adj[i][j]){
					// A는 항상 매칭에 포함된 정점임을 증명할 수 있다
					assert(aMatch[i] != -1);
					aChosen[i] = false;
					bChosen[aMatch[i]] = true;
					changed = true;
				}
			}
		}
		if(!changed) break;
	}
}

void makeGraph(){
	int dy[]={1,-1,0,0};
	int dx[]={0,0,1,-1};

	memset(id, -1, sizeof(id));
	N = M = 0;
	for(int y=0; y<H; y++){
		for(int x=0; x<W; x++){
			if(board[y][x] == '.'){
				if((y+x)%2 == 0) id[y][x] = N++;
				else id[y][x] = M++;
			}
		}
	}

	memset(adj, 0, sizeof(adj));
	for(int y=0; y<H; y++){
		for(int x=0; x<W; x++){
			if(((y+x)%2 == 0) && board[y][x] == '.') {
				for(int k=0; k<4; k++){
					int ny = y+dy[k];
					int nx = x+dx[k];
					if(
						(ny>=0 && ny<H && nx>=0 && nx<W) 
							&& board[ny][nx]=='.')
					{
						adj[id[y][x]][id[ny][nx]] = 1;
					}
				}
			}
		}
	}
}

void printTraps(){
	int C=0;
	for(int y=0;y<H;y++){
		for(int x=0;x<W;x++){
			if(board[y][x] == '.'){
				if(
					((y+x)%2 == 0 && aChosen[id[y][x]]) ||
					((y+x)%2 == 1 && bChosen[id[y][x]])
				){
					board[y][x] = '^';
					++C;
				}
			}
		}
	}

	printf("%d\n", C);
	for(int i=0; i<H; i++){
		cout << board[i] << '\n';
	}
}


int main(int argc, char **argv){
	//freopen("s_in_1129.txt", "r", stdin);
	int C; scanf("%d",&C);
	while(C--){
		scanf("%d%d",&H,&W);

		board.clear();
		board.resize(H);
		for(int i=0; i<H; i++){
			cin >>board[i];
		}

		makeGraph();
		calcMaxIndependentSet();
		printTraps();
	}
}
