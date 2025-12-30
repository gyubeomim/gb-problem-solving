#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstring>

#define pii pair<int,int>
#define ll long long

using namespace std;
int N;
int shark =2;
int feed = 0;
int board[20][20] = {0};

struct Fish {
	int r;
	int c;
	int t;
};

int t = 0;

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

int sx=0;
int sy=0;

vector<Fish> fishes;
int visited[20][20] = {0};

bool comp(const Fish &a, const Fish &b) {
	if(a.t == b.t) {
		if(a.r == b.r) {
			return a.c < b.c;
		}
		return a.r < b.r;
	}
	return a.t < b.t;
}

bool FindFish() {
	fishes.clear();
	memset(visited, -1, sizeof(visited));

	queue<pair<int,int>> Q;

	Q.push(make_pair(sx, sy));
	visited[sx][sy] = 0;

	while(!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for(int d=0; d<4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			if(nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
			if(board[nr][nc] > shark) continue;
			if(visited[nr][nc] > -1) continue;

			Q.push({nr, nc});
			visited[nr][nc] = visited[r][c] +1;
			// cout << "Search nrnc: " << nr << ", " << nc << ", rc: " << r << ", " << c << ", visited: " << visited[nr][nc] << ", " << visited[r][c] << endl;

			if(shark > board[nr][nc] && board[nr][nc] > 0) {
				Fish f;
				f.r = nr;
				f.c = nc;
				f.t = visited[r][c] + 1;
				fishes.push_back(f);
			}
		}
	}
	
	if(!fishes.empty()) {
		sort(fishes.begin(), fishes.end(), comp);

		Fish f = fishes[0];

		sx = f.r;
		sy = f.c;

		board[sx][sy] = 0;

		feed++;
		if(feed >= shark) {
			shark++;
			feed = 0;
		}

		t += f.t;

		return true;
	}
	else {
		return false;
	}

}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++){
			cin >> board[i][j];
			if(board[i][j] == 9) {
				sx = i;
				sy = j;
			}
		}
	}

	board[sx][sy] = 0;

	while(true) {
		if(!FindFish()) {
			cout << t;
			break;
		}
	}



	return 0;
}
