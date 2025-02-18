#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

const int LM = 1005;

string board[LM];
int dist1[LM][LM];  // 불의 전파 시간
int dist2[LM][LM];  // 지훈이의 이동 시간

int N, M;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(int argc, char **argv) {
  scanf("%d%d", &N, &M);

  for (int i = 0; i < N; i++) {
    fill(dist1[i], dist1[i] + M, -1);
    fill(dist2[i], dist2[i] + M, -1);
  }

  for (int i = 0; i < N; i++) cin >> board[i];

  queue<pii> Q1, Q2;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 'F') {
        Q1.push({i, j});
        dist1[i][j] = 0;
      }
      if (board[i][j] == 'J') {
        Q2.push({i, j});
        dist2[i][j] = 0;
      }
    }
  }

  // 불에 대한 BFS
  while (!Q1.empty()) {
    auto cur = Q1.front();
    Q1.pop();
    for (int d = 0; d < 4; d++) {
      int nx = cur.X + dx[d];
      int ny = cur.Y + dy[d];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
      Q1.push({nx, ny});
    }
  }

  // 지훈이에 대한 BFS
  while (!Q2.empty()) {
    auto cur = Q2.front();
    Q2.pop();
    for (int d = 0; d < 4; d++) {
      int nx = cur.X + dx[d];
      int ny = cur.Y + dy[d];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
        printf("%d\n", dist2[cur.X][cur.Y] + 1);
        return 0;
      }
      if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
        continue;

      dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
      Q2.push({nx, ny});
    }
  }
  printf("IMPOSSIBLE\n");
}
