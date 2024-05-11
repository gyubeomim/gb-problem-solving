#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
using namespace std;

constexpr int LM = 1005;

struct Data {
	int x;
	int y;
};

int M,N;
int arr[LM][LM];
int answer = 0;
int visited[LM][LM];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0,0,-1,1};
queue<Data> Q;

void BFS2(){
	while(!Q.empty()){
		int qsize = Q.size();
		for(int i=0; i<qsize; i++) {
			Data data = Q.front();
			Q.pop();
			for(int d=0; d<4; d++){
				int nx = data.x + dx[d];
				int ny = data.y + dy[d];

				if(nx < 0 || nx > N-1 || ny < 0 || ny >M-1) continue;
				if(visited[nx][ny]) continue;
				if(arr[nx][ny] == -1) continue;
				if(arr[nx][ny] == 1) continue;

				visited[nx][ny] = 1;
				arr[nx][ny] = 1;
				Q.push({nx, ny});
			}
		}
		answer++;
	}
}

int main(int argc, char **argv){
	 memset(visited,0,sizeof(visited));

	 scanf("%d %d", &M, &N);
	 for(int i=0; i<N; i++){
		 for(int j=0; j<M; j++){
			 int n;
			 scanf("%d", &n);
			 arr[i][j] = n;
			 if(n==-1) visited[i][j] = 1;
			 if(n==1) {
				 Q.push({i,j});
				 visited[i][j]=1;
			 }
		 }
	 }

	 BFS2();

	 for(int i=0; i<N; i++){
		 for(int j=0; j<M; j++){
			 if(arr[i][j] == 0)
				 answer = -1;
		 }
	 }
	 printf("%d", answer > 0 ? answer-1 : answer);
}
