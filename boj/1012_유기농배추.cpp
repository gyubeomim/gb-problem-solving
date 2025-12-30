#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int xoff[4] = {-1,1,0,0};
int yoff[4] = {0,0,-1,1};
int board[50][50]={0};
bool visited[50][50] = {0};
int N,M,K;

bool bfs(int x, int y){
  if(board[x][y] == 0) return false;
  if(visited[x][y]) return false;

  visited[x][y] = true;

  queue<pair<int,int> > Q;
  Q.push(make_pair(x,y));

  while(!Q.empty()){
    int qsize = Q.size();
    for(int i=0; i<qsize; i++){
      int x = Q.front().first;
      int y = Q.front().second;
      Q.pop();

      for(int d=0; d<4; d++){
        int nx = x + xoff[d];
        int ny = y + yoff[d];

        if(nx < 0 || ny < 0 || nx >=N || ny >=M) continue;
        if(board[nx][ny] == 0) continue;
        if(visited[nx][ny]) continue;

        visited[nx][ny] = 1;
        Q.push(make_pair(nx,ny));
      }
    }
  }

  return true;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int T=0;
  cin >> T;

  while(T--){

    cin >> N >> M >> K;

    memset(board,0,sizeof(board));
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<K; i++){
      int x,y;
      cin >> x >> y;
      board[x][y] = 1;
    }

    int nums=0;
    for(int i=0; i<50;i++){
      for(int j=0; j<50; j++){
        if(bfs(i,j)){
          nums++;
        }
      }
    }
    cout << nums << endl;
  }

  return 0;
}
