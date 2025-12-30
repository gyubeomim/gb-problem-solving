#include <bits/stdc++.h>

using namespace std;




int board[100][100]={0};
int visited[100][100]={0};


int N;


int roff[4] = {-1,1,0,0};
int coff[4] = {0,0,-1,1};









int bfs(int now) {
  int result = 0;

  memset(visited, 0, sizeof(visited));




  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {

      if (board[i][j] <= now && board[i][j] > 0) {
        visited[i][j] = 2;
				// cout << i << ", " << j << endl;
      }

    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {

      if (visited[i][j] == 1 || visited[i][j] == 2) {
        continue;
      }

      result++;

      queue<int> Q;
      Q.push(i * 100 + j);
      visited[i][j] = 1;

      while (!Q.empty()) {
        int qsize = Q.size();

        for (int k = 0; k < qsize; k++) {

          int r = Q.front() / 100;
          int c = Q.front() % 100;
          Q.pop();

          for (int d = 0; d < 4; d++) {
            int nr = r + roff[d];
            int nc = c + coff[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
              continue;
            if (visited[nr][nc] == 2 || visited[nr][nc] == 1)
              continue;
            if (board[nr][nc] <= now) continue;

            visited[nr][nc] = 1;
            Q.push(nr * 100 + nc);

            // cout << "nrnc: " << nr << ", " << nc << endl;
          }
        }
      }
    }
  }







        return result;
}








int main() {

  cin >> N;

  int min_ = 9999;
  int max_ = 0;




  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int num;
      cin >> num;

      min_ = min(min_, num);
      max_ = max(max_, num);

      board[i][j] = num;
    }
  }







  int ans = 0;

  for (int i = 0; i <= max_; i++) {
    int result = bfs(i);

    // cout << "i: " << i << ", " << ans << ", " << result << endl;

    ans = max(result, ans);
  }

  cout << ans << '\n';

  return 0;
}