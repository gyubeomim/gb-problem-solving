#include <bits/stdc++.h>
using namespace std;

const int LM = 1005;
enum { UNWATCHED = 0,
       WATCHED,
       INSTALLED };

int H;
int V;
vector<int> adj[LM];
vector<bool> visited;

int installed;

int dfs( int here ) {
  visited[here] = true;
  int children[3] = { 0, 0, 0 };
  for ( int i = 0; i < adj[here].size(); i++ ) {
    int there = adj[here][i];
    if ( !visited[there] )
      ++children[dfs( there )];
  }

  // 자손 노드 중 감시되지 않은 노드가 있을 경우 카메라를 설치한다
  if ( children[UNWATCHED] ) {
    ++installed;
    return INSTALLED;
  }
  // 자손 노드 중 카메라가 설치된 노드가 있을 경우 설치할 필요가 없다
  if ( children[INSTALLED] )
    return WATCHED;

  return UNWATCHED;
}

int installCamera() {
  installed = 0;
  visited = vector<bool>( V, false );

  for ( int u = 0; u < V; u++ ) {
    if ( !visited[u] && dfs( u ) == UNWATCHED )
      ++installed;
  }

  return installed;
}

int main( int argc, char **argv ) {
  // freopen("s_in_1121.txt", "r", stdin);
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    for ( int i = 0; i < LM; i++ ) adj[i].clear();

    scanf( "%d%d", &V, &H );

    for ( int i = 0; i < H; i++ ) {
      int a, b;
      scanf( "%d%d", &a, &b );
      adj[a].push_back( b );
      adj[b].push_back( a );
    }

    int ans = installCamera();
    printf( "%d\n", ans );
  }
}
