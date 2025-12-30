#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int N,M,D;
int arr[16][16];
int copy_arr[16][16];
bool visited[16][16] ={0};

vector<int> archers;

const int dx[3] = {0,-1,0};
const int dy[3] = {-1,0,1};

struct Node {
	int x;
	int y;
	int num;
};

int BFS() {
	int cnt =0;

	queue<pair<int,int>> enemies;

	for(int i=0; i<M; i++) {
		if(archers[i] == 1) {
			if(copy_arr[N-1][i] == 1) {
				enemies.push(make_pair(N-1,i));
				continue;
			}

			memset(visited, false, sizeof(visited));
			queue<Node> Q;
			Node n = {N-1, i, 1};
			Q.push(n);
			visited[N-1][i] = true;

			while(!Q.empty()) {
				int x = Q.front().x;
				int y = Q.front().y;
				int num = Q.front().num;
				Q.pop();

				if(num > D) continue;

				if(copy_arr[x][y] == 1) {
					enemies.push(make_pair(x,y));
					break;
				}
				
				for(int j=0; j<3; j++){
					int nx = x+dx[j];
					int ny = y+dy[j];

					if(x<0 || x>=N || y<0 || y>=M) continue;
					if(!visited[nx][ny]) {
						Node nn = {nx, ny, num+1};
						Q.push(nn);
						visited[nx][ny] = true;
					}
				}

			}

		}
	}

	while(!enemies.empty()) {
		int x = enemies.front().first;
		int y = enemies.front().second;
		enemies.pop();

		if(copy_arr[x][y] == 1) {
			cnt ++ ;
			copy_arr[x][y] = 0;
		}
	}

	return cnt;
}

bool Search() {
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) {
			if(copy_arr[i][j] == 1) return true;
		}
	}

	return false;
}

void Next() {
	for(int c=M-1; c>=0; c--) {
		for (int r=N-1; r>=0; r--) {
			if(r == N-1) {
				copy_arr[r][c] = 0;
			}
			else {
				if(copy_arr[r][c] == 1) {
					copy_arr[r][c] = 0;
					copy_arr[r+1][c] = 1;
				}
			}
		}
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>M>>D;

	for(int i=0; i<N;i++){
		for(int j=0; j<M; j++){
			cin >> arr[i][j];
		}
	}

	for(int i=0;i<M-3;i++){
		archers.push_back(0);
	}
	for(int i=0;i<3;i++){
		archers.push_back(1);
	}

	int ans=0;
	do {
		 for(int i=0; i<N;i++){
			 for(int j=0; j<M;j++){
				 copy_arr[i][j] = arr[i][j];
			 }
		 }
		
		 int num=0;
		 while(Search()) {
			 num += BFS();
			 Next();
		 }

		 if(ans < num) {
			 ans = num;
		 }

	} while (next_permutation(archers.begin(), archers.end()));

	cout << ans;

	return 0;
}
