#include <bits/stdc++.h>
#define X first
#define Y second
using pii = std::pair<int,int>;
using namespace std;

const int LM = 2005;
const int INF = 0x3f3f3f3f;

int V,E;
vector<pair<int, pii>> edges;  // {weight, {u,v}}
vector<int> weights;

int p[LM], rk[LM];

int find(int x){
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

void Union(int u, int v){
  u=find(u), v=find(v);
  if(u==v) return;

  if(rk[v]<rk[u]) swap(u,v);
  p[u]=v;
  if(rk[u]==rk[v]) rk[v]++;

  return;
}

int kruskalMinUpper(int low){
  for(int i=0; i<V; i++){
    p[i] = i;  rk[i] = 0;
  }

  for(int i=0; i<edges.size(); i++){
    if(edges[i].X < weights[low]) continue;
    Union(edges[i].Y.X, edges[i].Y.Y);
    if(find(0) == find(V-1)) 
      return edges[i].X;
  }
  return INF;
}

int main(int argc, char **argv){
  //freopen("s_in_2266.txt", "r", stdin);
  int C; scanf("%d",&C);
  while(C--) {
    scanf("%d%d",&V,&E);

    edges = vector<pair<int, pii>>();
    weights.clear();

    for(int i=0 ;i<E; i++){
      int a, b, speed;
      scanf("%d%d%d", &a, &b, &speed);
      edges.push_back({speed,{a, b}});
    }

    sort(edges.begin(), edges.end());

    for(int i=0; i<E; i++){ weights.push_back(edges[i].X); }

    int ret = INF;

    for(int i=0;i<E; i++){
      ret = min(ret, kruskalMinUpper(i) - weights[i]);
    }
    printf("%d\n", ret);
  }
}
