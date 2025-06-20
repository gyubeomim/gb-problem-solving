#include <bits/stdc++.h>
using namespace std;

const int LM = 205;
const int INF = 0x3f3f3f3f;

int V,M,N;
int adj[LM][LM];

// 간선 (a,b)를 추가했을 때 그래프의 최단거리 배열 adj를 적절히 갱신한다. 간선이 아무런 의미가 없을 경우 false를 반환한다
bool update(int a, int b, int c){
  if(adj[a][b] <= c) return false;

  for(int x=0;x<V;x++){
    for(int y=0;y<V;y++){
      // x~y 최단경로가 (a,b)를 이용하려면 x~a~b~y 혹은 x~b~a~y의 형태를 가져야 한다
      adj[x][y] = min( {adj[x][y], adj[x][a] + c + adj[b][y], adj[x][b] + c + adj[a][y]} );
    }
  }
  return true;
}

int main(int argc, char **argv){
  //freopen("s_in_2244.txt", "r", stdin);
  int C; scanf("%d",&C);
  while(C--) {
    scanf("%d%d%d", &V, &M, &N);

    memset(adj, 0x3f, sizeof(adj));

    for(int i=0;i<V;i++) { adj[i][i] = 0; }

    for(int i=0;i<M;i++){
      int a,b,c;
      scanf("%d%d%d", &a,&b,&c);
      update(a,b,c);
    }

    for(int k=0;k<V;k++){
      for(int i=0;i<V;i++){
        if(adj[i][k] == INF) continue;
        for(int j=0;j<V;j++){
          if(adj[i][j] > adj[i][k]+adj[k][j]) {
            adj[i][j] = adj[i][k]+adj[k][j];
          }
        }
      }
    }

    int ans =0 ;
    for(int i=0;i<N;i++){
      int a,b,c;
      scanf("%d%d%d", &a,&b,&c);
      if(!update(a,b,c)) ans++;
    }
    printf("%d\n", ans);
  } 
}
