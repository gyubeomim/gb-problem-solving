#include <bits/stdc++.h>
using namespace std;

const int LM = 1000005;

vector<int> p(LM, -1);

int find( int x ) {
  if ( p[x] < 0 ) return x;
  return p[x] = find( p[x] );
}

bool Union( int u, int v ) {
  u = find( u ), v = find( v );
  if ( u == v ) return 0;

  if ( p[v] < p[u] ) swap( u, v );
  if ( p[u] == p[v] ) p[u]--;
  p[v] = u;
  return 1;
}

int main( int argc, char **argv ) {
  int N, M;
  scanf( "%d%d", &N, &M );

  while ( M-- ) {
    int q, a, b;
    scanf( "%d%d%d", &q, &a, &b );

    if ( q == 0 )
      Union( a, b );
    else {
      if ( find( a ) == find( b ) )
        printf( "YES\n" );
      else
        printf( "NO\n" );
    }
  }
}
