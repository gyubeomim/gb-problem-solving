#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int roff[4] = {-1,1,0,0};
const int coff[4] = {0,0,-1,1};

int main() {
  int T;
  cin >> T;

  for(int t=0; t<T; t++) {
    int W,H;
    char map[1000][1000];
    bool visited[1000][1000]={false};
    cin >> W >> H;

    queue<int> Q, FQ;

    for(int i=0; i<H; i++) {
      getchar();
      for(int j=0; j<W; j++) {
        map[i][j] = getchar();

        if(map[i][j] == '@') {
          visited[i][j] = true;
          Q.push(i*1000 + j);
        }
        if(map[i][j] == '*') {
          FQ.push(i*1000 + j);
        }
      }
    }

    bool success = false;
    int result = 0;
    while(!Q.empty()) {
      result++;
      int qSize=Q.size();
      for(int i=0; i<qSize; i++) {
        int r = Q.front()/1000;
        int c = Q.front()%1000;
        Q.pop();

        if(map[r][c] == '*') continue;

        for(int d=0; d<4; d++) {
          int nr = r + roff[d];
          int nc = c + coff[d];

          if(nr<0 || nr>=H || nc<0 || nc>=W) {
            success = true;
            break;
          }
          if(map[nr][nc]=='.' && !visited[nr][nc]) {
            visited[nr][nc] = true;
            Q.push(nr*1000 + nc);
          }
        }
      }
      if(success) break;

      qSize = FQ.size();
      for(int i=0; i<qSize; i++) {
        int r = FQ.front()/1000;
        int c = FQ.front()%1000;
        FQ.pop();

        for(int d=0; d<4; d++) {
          int nr = r + roff[d];
          int nc = c + coff[d];

          if(nr<0 || nr>=H || nc<0 || nc>=W) continue;
          if(map[nr][nc]=='.') {
            map[nr][nc] = '*';
            FQ.push(nr*1000 + nc);
          }
        }
      }
    }
    if(success)
      cout << result << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
