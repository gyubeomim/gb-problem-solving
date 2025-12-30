#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

int main() {
  int N,M;
  cin >> N >> M;

  bool map[1000][1000];
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      scanf("%1d", &map[i][j]);
    }
  }

  bool visited[2][1000][1000] = {false};
  visited[0][0][0] = true;

  queue<int> q;
  q.push(0);
  int result = 1;

  while(!q.empty()) {
    int qSize = q.size();
    bool reach = false;

    for(int i=0; i<qSize; i++) {
      bool crash = q.front() / (M*N);
      int x = q.front() % (M*N) / M;
      int y = q.front() % M;
      q.pop();

      if(x == N-1 && y == M-1) {
        reach = true;
        break;
      }

      for(int d=0; d<4; d++) {
        int nextX = x + dx[d];
        int nextY = y + dy[d];

        if(nextX<0 || nextX>=N || nextY<0 || nextY>=M) continue;
        if(visited[crash][nextX][nextY]) continue;
        if(map[nextX][nextY]) {
          if(crash) continue;
          visited[1][nextX][nextY] = true;
          q.push(M*N + nextX*M + nextY);
        }
        else {
          visited[crash][nextX][nextY] = true;
          q.push(crash*M*N + nextX*M + nextY);
        }
      }
    }
    if(reach) break;
    result++;
  }

  if(visited[0][N-1][M-1] || visited[1][N-1][M-1])
    cout << result << endl;
  else
    cout << "-1" << endl;


  return 0;
}
