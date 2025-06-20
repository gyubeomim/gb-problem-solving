#include <bits/stdc++.h>
#define X first
#define Y second
using pii = std::pair<int,int>;
using namespace std;

const int LM = 500;
const int INF = 0x3f3f3f3f;
int N,M;
vector<vector<double>> dist;
pii bpos[LM];

double prim(){
  vector<bool> added(N, false);
  vector<double> min_weight(N, INF);

  double ret = 0;

  // 시작은 정점 0부터
  min_weight[0] = 0;
  for (int iter = 0; iter < N; iter++) {
    int u = -1;

    for(int v=0; v<N; v++){
      // 현재 저장된 min weight 중 가장 작은 정점으로
      if(!added[v] && (u==-1 || min_weight[u] > min_weight[v])) 
        u = v;
    }

    // 스패닝 트리에 추가
    ret += min_weight[u];
    added[u] = true;

    double weight;
    for(int v=0; v<N; v++){
      if(added[v]) continue;

      weight = dist[u][v];
      if(min_weight[v] > weight) 
        min_weight[v] = weight;
    }
  }

  return ret;
}

int main(int argc, char **argv){
  //freopen("s_in_2255.txt", "r", stdin);

  int C; scanf("%d",&C);
  while(C--) {
    scanf("%d%d", &N, &M);

    dist = vector<vector<double>>(N, vector<double>(N, -1));

    int x,y;
    for(int i=0; i<N; i++){
      scanf("%d",&x);
      bpos[i].X = x;
    }
    for(int i=0; i<N; i++){
      scanf("%d",&y);
      bpos[i].Y = y;
    }

    int u,v,xcap,ycap;
    double len;
    for(int i=0; i<M; i++){
      scanf("%d%d", &u, &v);
      dist[u][v]=dist[v][u] = 0;
    }

    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(dist[i][j]==-1){
          xcap = abs(bpos[i].X - bpos[j].X);
          ycap = abs(bpos[i].Y - bpos[j].Y);
          len = pow(xcap,2) + pow(ycap,2);
          len = sqrt(len);
          dist[i][j] = dist[j][i] = len;
        }
      }
    }

    double ans = prim();
    printf("%.10f\n", ans);

  } 
}
