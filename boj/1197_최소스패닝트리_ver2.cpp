#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int,int,int>;

vector<int> p(10005,-1);

int find(int x){
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool isDiffGroup(int a, int b){
  a = find(a); b = find(b);
  if(a == b) return 0;

  if(p[a] == p[b]) p[a]--;
  if(p[a] < p[b]) p[b] = a;
  else p[a] = b;

  return 1;
}

int v, e;
tiii edge[100005];

int main(void) {
  scanf("%d%d", &v, &e);
  for(int i = 0; i < e; i++){
    int a, b, cost;
    scanf("%d%d%d",&a,&b,&cost);
    edge[i] = {cost, a, b};
  }

  sort(edge, edge + e);

  int cnt = 0;
  int ans = 0;

  // Kruskal algorithm (using Union-find)
  for(int i = 0; i < e; i++){
    int a, b, cost;
    tie(cost, a, b) = edge[i];

    if(!isDiffGroup(a, b)) continue;

    ans += cost;
    cnt++;
    if(cnt == v-1) break;
  }

  printf("%d\n", ans);
}

