#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int xoff[8] = {2,2,1,1,-2,-2,-1,-1};
int yoff[8] = {-1,1,2,-2,-1,1,2,-2};
int board[300][300] = {0};
bool visited[300][300] = {0};
int currx, curry;
int targetx, targety;
int I;

int bfs(int x, int y){
  if(x == targetx && y == targety) return 0;

  queue<pair<int,int>> Q;
  Q.push(make_pair(x,y));
  visited[x][y] = 1;

  int count=0;

  while(!Q.empty()){
    int qsize = Q.size();

    for(int i=0; i<qsize; i++){
      int cx = Q.front().first;
      int cy = Q.front().second;
      Q.pop();

      if(cx == targetx && cy == targety){
        return count;
      }

      for(int d=0; d<8; d++){
        int nx = cx + xoff[d];
        int ny = cy + yoff[d];

        if(nx<0 || ny<0 || nx>=I || ny>=I) continue;
        if(board[nx][ny] == 0) continue;
        if(visited[nx][ny]) continue;

        visited[nx][ny] = 1;
        Q.push(make_pair(nx,ny));
      }
    }
    count++;
  }
  return -1;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int T;
  cin >> T;

  while(T--){
    cin >> I;

    memset(board, 0, sizeof(board));
    memset(visited, 0, sizeof(visited));

    for(int i=0;i<I;i++){
      for(int j=0;j<I;j++){
        board[i][j] = 1;
      }
    }


    cin >> currx >> curry;
    cin >> targetx >> targety;

    int nums = bfs(currx, curry);

    cout << nums << endl;
  }

  
  return 0;
}
