#include <bits/stdc++.h>
using namespace std;

const int LM = 12;

int c[1 << ( LM * 2 )];

int Get( int state, int index ) {
  return ( state >> ( index * 2 ) ) & 3;
}

int Set( int state, int index, int value ) {
  return ( state & ~( 3 << ( index * 2 ) ) | ( value << ( index * 2 ) ) );
}

// x의 부호를 반환한다
int sgn( int x ) {
  if ( !x ) return 0;
  return x > 0 ? 1 : -1;
}

// x의 절대값을 1 증가시킨다
int incr( int x ) {
  if ( x < 0 ) return x - 1;
  return x + 1;
}

// discs개의 원반이 있고 각 원반의 시작 위치와 목표 위치가 begin, end에 주어질 때 최소 움직임의 수를 계산한다
int bidir( int discs, int begin, int end ) {
  if ( begin == end ) return 0;

  memset( c, 0, sizeof( c ) );

  queue<int> q;
  q.push( begin );
  c[begin] = 1;
  q.push( end );
  c[end] = -1;

  while ( !q.empty() ) {
    int here = q.front();
    q.pop();
    int top[4] = { -1, -1, -1, -1 };

    for ( int i = discs - 1; i >= 0; i-- ) {
      top[Get( here, i )] = i;
    }

    for ( int i = 0; i < 4; i++ ) {
      if ( top[i] != -1 ) {
        for ( int j = 0; j < 4; j++ ) {
          if ( i != j && ( top[j] == -1 || top[j] > top[i] ) ) {
            int there = Set( here, top[i], j );
            // 아직 방문하지 않은 정점인 경우
            if ( c[there] == 0 ) {
              c[there] = incr( c[here] );
              q.push( there );
            }
            // 가운데서 만난 경우
            else if ( sgn( c[there] ) != sgn( c[here] ) ) {
              return abs( c[there] ) + abs( c[here] ) - 1;
            }
          }
        }
      }
    }
  }
  return -1;
}
int N;
int main( int argc, char **argv ) {
  // freopen("s_in_1234.txt", "r", stdin);
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d", &N );

    int start = 0;
    for ( int i = 0; i < 4; i++ ) {
      int num, dsize;
      scanf( "%d", &num );
      for ( int j = 0; j < num; j++ ) {
        scanf( "%d", &dsize );
        start = Set( start, dsize - 1, i );
      }
    }

    int dest = 0;
    for ( int i = 0; i < N; i++ ) {
      dest = Set( dest, i, 3 );
    }

    int ans = bidir( N, start, dest );
    printf( "%d\n", ans );
  }
}
