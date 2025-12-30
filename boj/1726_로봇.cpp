#include <bits/stdc++.h>

using namespace std;

struct robot {
  int x, y, d;
};
int n, m;
int sx, sy, sd, ex, ey, ed;
int board[100][100];
int dist[100][100][4];


// dir = E(1), W(2), S(3), N(4)
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void bfs() {
  queue<robot> Q;
  Q.push({sx-1, sy-1, sd-1});




  while(!Q.empty()) {
    int x = Q.front().x;
    int y= Q.front().y;
    int d = Q.front().d;
    Q.pop();


    if(x == ex-1 && y == ey-1 && d == ed-1) {
      cout << dist[x][y][d] << '\n';
      return; 
    }



    for(int i=1; i<=3; i++) {
      int nx = x + dx[d]*i;
      int ny = y + dy[d]*i;

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
      if(board[nx][ny]) break;
      if(dist[nx][ny][d]) continue;
      

      Q.push({nx, ny, d});
      dist[nx][ny][d] = dist [x][y][d] + 1;
    }



    for(int i=0; i<4; i++) {
      if(i == d) continue;
      int k = (i + d) % 4 == 1 ? 2 : 1;
      if(dist[x][y][i]) continue;


      Q.push({x,y,i});
      dist[x][y][i] = dist[x][y][d] + k;


    }

  }
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	scanf("%d %d %d", &sx, &sy, &sd);
	scanf("%d %d %d", &ex, &ey, &ed);

	bfs();
}