#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using tiii = std::tuple<int,int,int>;
using ll = long long;
using namespace std;

const int LM = 100005;
const int N = 305;

int V, E;
tiii edge[LM];

vector<int> p( N, -1 );
int find( int x ) {
  if ( p[x] < 0 ) return x;
  return p[x] = find( p[x] );
}

bool isDiffGroup( int u, int v ) {
  u = find( u ), v = find( v );
  if ( u == v ) return 0;

  if ( p[u] == p[v] ) p[u]--;
  if ( p[u] < p[v] )  p[v] = u;
  else  p[u] = v;

  return 1;
}

int main( int argc, char **argv ) {
  scanf( "%d", &V );

  // 가상의 V+1번째 정점과 연결
  for ( int i = 1; i <= V; i++ ) {
    int cost;
    scanf( "%d", &cost );
    edge[E++] = { cost, i, V + 1 };
  }

  for ( int i = 1; i <= V; i++ ) {
    for ( int j = 1; j <= V; j++ ) {
      int cost;
      scanf( "%d", &cost );
      if ( i >= j ) continue;
      edge[E++] = { cost, i, j };
    }
  }

  V++;  // 가상의 정점까지 포함해야 하므로 정점 수를 1 증가시킴
  sort( edge, edge + E );

  int cnt = 0;
  int ans = 0;
  for ( int i = 0; i < E; i++ ) {
    int a, b, cost;
    tie( cost, a, b ) = edge[i];
    if ( !isDiffGroup( a, b ) ) continue;
    ans += cost;
    cnt++;
    if ( cnt == V - 1 ) break;
  }
  printf( "%d\n", ans );
}
