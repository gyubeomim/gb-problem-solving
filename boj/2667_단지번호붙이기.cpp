#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N;
const int roff[5] = {0, -1, 1, 0, 0};
const int coff[5] = {0, 0, 0, -1, 1};
bool map[25][25];
bool visited[25][25] = {0};
queue<int> Q;
vector<int> v;

int bfs(int r, int c) {
  if (map[r][c] == 1) {
    Q.push(r * 25 + c);
  }

  int num = 0;
  while (!Q.empty()) {
    int qSize = Q.size();
    for (int i = 0; i < qSize; i++) {
      r = Q.front() / 25;
      c = Q.front() % 25;
      Q.pop();
      //cout << "r: " << r << ", c: " << c << endl;
      for (int d = 0; d < 5; d++) {
        int nr = r + roff[d];
        int nc = c + coff[d];

        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if (!map[nr][nc]) continue;
        if (visited[nr][nc]) continue;

        visited[nr][nc] = true;
        Q.push(25 * nr + nc);
        num += 1;
        // cout << nr << ", " << nc << ", num: " << num << endl;
      }
    }
  }
  // cout << "-----------------------------\n";
  return num;
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%1d", &map[i][j]);
    }
  }
  int count = 0;
  int num = 0;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      num = bfs(r, c);
      if (num != 0) {
        count += 1;
        v.push_back(num);
      }
    }
  }

  cout << count << '\n';
  std::sort(v.begin(), v.end());
  for(auto it : v) {
    cout << it << '\n';
  }

  return 0;
}