#include <bits/stdc++.h>
using pii = std::pair<int,int>;
using namespace std;

const int LM = 505;
const int INF = 0x3f3f3f;
int V, adj[LM][LM];
int E;

int delay[LM];
int W[LM][LM];

void solve(){
  vector<pii> order;
  for(int i=0;i<V;i++){
    order.push_back( {delay[i], i} );
  }
  sort(order.begin(), order.end());

  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      if(i == j) W[i][j] = 0;
      else W[i][j] = adj[i][j];
    }
  }

  int ret = INF;
  for(int k=0; k<V; k++){
    // k번째로 예상 시간이 적게 걸리는 정점 w까지를 지나서 얻을 수 있는 최단거리
    int w = order[k].second;
    for(int i=0; i<V; i++){
      for(int j=0; j<V; j++){
        adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
        W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
      }
    }
  }

}

int main(int argc, char **argv){
  //freopen("s_in_2233.txt", "r", stdin);
  scanf("%d%d",&V,&E);

  for(int i=0; i<V; i++){
    scanf("%d", &delay[i]);
  }

  memset(adj, 0x3f, sizeof(adj));

  for(int i=0; i<E; i++){
    int a,b,c;
    scanf("%d%d%d", &a,&b,&c);
    adj[a-1][b-1] = adj[b-1][a-1] = c;
  }

  solve();

  int C; scanf("%d",&C);
  while(C--) {
    int s,t;
    scanf("%d%d", &s,&t);
    printf("%d\n", W[s-1][t-1]);
  }
}
