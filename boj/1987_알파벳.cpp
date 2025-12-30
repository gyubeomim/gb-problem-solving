#include <bits/stdc++.h>

using namespace std;

int R, C;

char board[20][20] = {0};
bool visit[1000] = {0};

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int dfs(int now) {
  int ret = 0;

  int r = now / 20;
  int c = now % 20;

  visit[board[r][c]] = true;

  for (int d = 0; d < 4; d++) {
    int nr = r + dr[d];
    int nc = c + dc[d];

    if (nr < 0 || nr >= R || nc < 0 || nc >= C)     continue;

    if (visit[board[nr][nc]])       continue;


    ret = std::max(ret, dfs(nr * 20 + nc));
  }
  visit[board[r][c]] = false;

  return ret + 1;
}

int main() {
  cin >> R >> C;

  string s;
  for (int i = 0; i < R; i++) {
    cin >> s;

    for (int j = 0; j < C; j++) {
      board[i][j] = s[j];
      // cout << "s[j]: " << s[j] << endl;
    }
  }

  cout << dfs(0) << '\n';
  ;

  return 0;
}