#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

vector<vector<pii>> rotations; // 블록의 각 회전된 형태를 상대 좌표의 목록으로 저장해둔다
int blockSize;

int N, M, R, C;
vector<string> board, block;
// 게임판의 각 칸이 덮였는지를 나타낸다. 1이면 검은 칸이거나 이미 덮은 칸, 0이면 빈칸
int covered[10][10];
// 지금까지 찾은 최적해
int best; 

// 2차원 배열 arr을 시계방향으로 90도 돌린 경과를 반환한다
vector<string> rotate(const vector<string>& arr){
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr[0].size();j++){
			ret[j][arr.size()-i-1] = arr[i][j];
		}
	}
	return ret;
}

// block의 네 가지 회전 형태를 만들고 이들을 상대 좌표의 목록으로 반환한다
void generateRotations(vector<string> block){
	rotations.clear(); 
	rotations.resize(4);

	for(int rot=0;rot<4;rot++){
		int originY = -1, originX = -1;
		for(int i=0; i<block.size(); i++){
			for(int j=0; j<block[i].size(); j++){
				if(block[i][j]=='#') {
					if(originY==-1){
						// 가장 윗줄 맨 왼쪽에 있는 칸이 원점이된다
						originY=i;
						originX=j;
					}
					rotations[rot].push_back( {i-originY, j-originX} );
				}
			}
		}
		block = rotate(block);
	}
	// 네 가지 회전 형태 중 중복이 있을 경우 이를 제거한다
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	// 블록이 몇 칸 짜리인지 저장해둔다
	blockSize = rotations[0].size();
}

// (y,x)를 왼쪽 위칸으로 해서 주어진 볼록을 delta=1이면 놓고 -1이면 없앤다
// 블록을 놓을 때 이미 놓인 블록이나 검은 칸과 겹치면 거짓을 아니면 참을 반환한다
bool Set(int y, int x, const vector<pii>& block, int delta){
		bool ok = true;
    for(int i = 0; i < block.size(); i++) {
        int cy = y + block[i].first;
				int cx = x + block[i].second;

        if(cy < 0 || cx < 0 || cy >= N || cx >= M) ok = false;
        else {
            covered[cy][cx] += delta;
            if(covered[cy][cx] > 1) ok = false;
        }
    }
    return ok;
}

bool pruning(int placed) {
	int empty=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(covered[i][j]==0) 
				empty++;
		}
	}
	return (empty/blockSize) + placed <= best ? true : false;
}

// placed: 지금까지 놓은 블록의 수
void search(int placed){
	if(pruning(placed)) return; 

	// 아직 채우지 못한 빈 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다
	int y=-1,x=-1;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(covered[i][j]==0){
				y=i; x=j; break;
			}
		}
		if(y!=-1)break;
	}

	// 기저사례: 게임판의 모든 칸을 처리한 경우
	if(y==-1){
		best=max(best, placed);
		return;
	}

	// 이 칸을 덮는다
	for(int i=0;i<rotations.size();i++){
		if(Set(y,x,rotations[i],1)) 
			search(placed+1);
		Set(y,x,rotations[i],-1);
	}
	// 이 칸을 덮지 않고 막아둔다
	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
}

int solve(){
	// 초기화
	best=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
		}
	}
	search(0);
	return best;
}

int main(int argc, char **argv){
	// freopen("data/s_in_13321.txt", "r", stdin);
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d",&N,&M,&R,&C)	;
		board.resize(N);
		for(int i=0; i<N; i++) cin >> board[i];
		block.resize(R);
		for(int i=0; i<R; i++) cin >> block[i];
		
		generateRotations(block);	
		int ans = solve();
		printf("%d\n", ans);
	}
}