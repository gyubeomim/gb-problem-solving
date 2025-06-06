#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH( x ) cout << #x << " : " << x << '\n';
#define PRINT( x ) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int, int>;
using ll = long long;
using namespace std;

const int LM = 10005;
int N, M;
int parent[LM], rk[LM], enemy[LM], sz[LM];

int find( int x ) {
  if ( parent[x] == x ) return x;
  return parent[x] = find( parent[x] );
}

int Union( int a, int b ) {
  if ( a == -1 || b == -1 ) return max( a, b );

  a = find( a );
  b = find( b );
  if ( a == b ) return b;

  if ( rk[a] < rk[b] ) swap( a, b );
  if ( rk[a] == rk[b] ) rk[a]++;

  parent[b] = a;
  sz[a] += sz[b];

  return a;
}

bool dis( int u, int v ) {
  u = find( u ), v = find( v );
  if ( u == v ) return false;  // 같은 집합에 속해 있으면 모순!

  // 적의 적은 나의 동지
  int a = Union( u, enemy[v] );
  int b = Union( v, enemy[u] );

  enemy[a] = b;
  enemy[b] = a;
  return true;
}

bool ack( int u, int v ) {
  u = find( u ), v = find( v );
  if ( enemy[u] == v ) return false;  // 두 집합이 서로 적대관계라면 모순!

  // 동지의 적은 나의 적
  int a = Union( u, v );
  int b = Union( enemy[u], enemy[v] );

  enemy[a] = b;
  if ( b != -1 )
    enemy[b] = a;  // 두 집합 다 적대하는 집합이 없으면 b는 -1일 수도 있다
  return true;
}

int findMaxParty() {
  int ret = 0;
  for ( int n = 0; n < N; n++ ) {
    if ( parent[n] == n ) {
      int e = enemy[n];

      if ( e > n ) continue;
      int mySize = sz[n];
      int enemySize = ( e == -1 ? 0 : sz[e] );

      ret += max( mySize, enemySize );
    }
  }
  return ret;
}

int main( int argc, char **argv ) {
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d%d", &N, &M );

    bool contradiction = false;
    int cid = 0;

    memset( parent, 0, sizeof( parent ) );
    memset( rk, 0, sizeof( rk ) );
    memset( enemy, 0, sizeof( enemy ) );
    memset( sz, 0, sizeof( sz ) );

    for ( int i = 0; i < N; i++ ) {
      parent[i] = i;
      rk[i] = 0;
      enemy[i] = -1;
      sz[i] = 1;
    }

    for ( int i = 1; i <= M; i++ ) {
      string S;
      int a, b;
      cin >> S >> a >> b;

      if ( contradiction ) continue;

      if ( S == "ACK" ) {
        if ( !ack( a, b ) ) {
          cid = i;
          contradiction = true;
        }
      } else if ( S == "DIS" ) {
        if ( !dis( a, b ) ) {
          cid = i;
          contradiction = true;
        }
      }
    }

    if ( contradiction )
      printf( "CONTRADICTION AT %d\n", cid );
    else
      printf( "MAX PARTY SIZE IS %d\n", findMaxParty() );
  }
}
