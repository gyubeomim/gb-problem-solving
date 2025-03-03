#include <bits/stdc++.h>
#define X first
#define Y second
using pii = std::pair<int,int>;
using namespace std;

const int LM = 10005;

int N;
int E[LM], M[LM];

int heat() {
  vector<pii> order;
  for ( int i = 0; i < N; i++ )
    order.push_back( make_pair( -E[i], i ) );  // 역순으로 정렬을 - 부호로 구현
  sort( order.begin(), order.end() );

  int ret = 0;
  int beginEat = 0;
  for ( int i = 0; i < N; i++ ) {
    int box = order[i].Y;
    beginEat += M[box];
    ret = max( ret, beginEat + E[box] );
  }
  return ret;
}

int main( int argc, char **argv ) {
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d", &N );

    memset( E, 0, sizeof( E ) );
    memset( M, 0, sizeof( M ) );

    for ( int i = 0; i < N; i++ ) {
      int m;
      scanf( "%d", &m );
      M[i] = m;
    }
    for ( int i = 0; i < N; i++ ) {
      int e;
      scanf( "%d", &e );
      E[i] = e;
    }

    int ans = heat();
    printf( "%d\n", ans );
  }
}
