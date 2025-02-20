#include <bits/stdc++.h>
using namespace std;

const int LM = 1000005;
vector<int> p( LM, -1 );

int find( int x ) {
  if ( p[x] < 0 ) return x;
  return p[x] = find( p[x] );
}

void Union( int a, int b ) {
  a = find( a );
  b = find( b );
  if ( a == b ) return;

  if ( p[a] < p[b] ) swap( a, b );
  if ( p[a] == p[b] ) p[a]--;
  p[b] = a;
}

int main( int argc, char **argv ) {
  int T;
  scanf( "%d", &T );

  for ( int tc = 1; tc <= T; tc++ ) {
    printf( "Scenario %d:\n", tc );
    int N, K;
    scanf( "%d%d", &N, &K );
    fill( p.begin() + 1, p.begin() + N + 1, -1 );
    while ( K-- ) {
      int a, b;
      scanf( "%d%d", &a, &b );
      Union( a, b );
    }

    int M;
    scanf( "%d", &M );
    while ( M-- ) {
      int u, v;
      scanf( "%d%d", &u, &v );
      printf( "%d\n", ( find( u ) == find( v ) ) );
    }
    puts( "" );
  }
}
