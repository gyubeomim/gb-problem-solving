#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[64][64];
int visited[64][64]={false};
const int roff[4]={-1,1,0,0};
const int coff[4]={0,0,-1,1};

vector<pair<int, int>> zeros;
int max_score=-9999;
int N, M;

int bfs(){
  memset(visited, 0, sizeof(visited));

  queue<int> Q;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if (map[i][j] == 4) map[i][j] = 0;
      if (map[i][j] == 2) {
        Q.push(i*64+j);
        visited[i][j]=true;
      }
    }
  }

  while(!Q.empty()){
    int qsize=Q.size();
    for(int i=0; i<qsize; i++){
      int r=Q.front()/64;
      int c=Q.front()%64;
      Q.pop();

      for(int d=0;d<4;d++){
        int nr=r+roff[d];
        int nc=c+coff[d];

        if(nr<0||nr>=N ||nc<0||nc>=M) continue;
        if(map[nr][nc]!=0) continue;
        if(visited[nr][nc]) continue;

        map[nr][nc] = 4;
        visited[nr][nc]=true;
        Q.push(nr*64+nc);
      }
    }
  }

  int score=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(map[i][j]==0){
        score +=1;
      }
    }
  }

  return score;
}

int main() {
  cin>>N>>M;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int x;
      cin>>x;
      map[i][j] = x;

      if(x==0){
        zeros.push_back(make_pair(i,j));
      }
    }
  }

  for(int i=0;i<zeros.size();i++){
    map[zeros.at(i).first][zeros.at(i).second] = 3;
    for(int j=i+1;j<zeros.size();j++){
      map[zeros.at(j).first][zeros.at(j).second] = 3;
      for(int k=j+1;k<zeros.size();k++){
        map[zeros.at(k).first][zeros.at(k).second] = 3;

        int score=bfs();
        if(max_score<score){
          max_score=score;
        }

        map[zeros.at(k).first][zeros.at(k).second] = 0;
      }
      map[zeros.at(j).first][zeros.at(j).second] = 0;
    }
    map[zeros.at(i).first][zeros.at(i).second] = 0;
  }

  cout<<max_score<<'\n';


}