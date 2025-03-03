// #2 DP ver1
#include <bits/stdc++.h>
using namespace std;

const int LM = 55;
const int LM2 = 105;

int N, D, P, Q;
double dp[LM][LM2];
// dp[here][days] : 두니발박사가 days일째에 here번 마을에 숨어 있을 때 마지막 날에 Q번 마을에 있을 조건부확률

int conn[LM][LM], deg[LM];
// conn[i][j] = 마을 i,j의 연결 여부
// deg[i] = 마을 i와 연결된 마을의 개수

// search2(here, days) = ( sum_{there in adj(here)} search2(there, days+1) ) / | adj(here) |
// adj(here) : here와 연결된 도시들의 집합
// 시간복잡도: O(n^2dt)
// O(nd)개의 문제를 각각 O(n) 시간에 해결
// t는 테스트 케이스
double search2( int here, int days ) {
  if ( days == D ) return ( here == Q ? 1.0 : 0.0 );

  double& ret = dp[here][days];
  if ( ret > -0.5 ) return ret;

  ret = 0.0;
  for ( int there = 0; there < N; there++ ) {
    if ( conn[here][there] )
      ret += search2( there, days + 1 ) / deg[here];
  }
  return ret;
}

int main( int argc, char** argv ) {
  int C;
  scanf( "%d", &C );

  while ( C-- ) {
    scanf( "%d%d%d", &N, &D, &P );

    memset( conn, 0, sizeof( conn ) );
    memset( deg, 0, sizeof( deg ) );

    for ( int i = 0; i < N; i++ ) {
      for ( int j = 0; j < N; j++ ) {
        scanf( "%d ", &conn[i][j] );
        if ( conn[i][j] ) deg[i]++;
      }
    }

    int T;
    scanf( "%d", &T );
    for ( int i = 0; i < T; i++ ) {
      scanf( "%d", &Q );
			memset( dp, -1, sizeof( dp ) );
      printf( "%.8lf ", search2( P, 0 ) );
    }
    puts( "" );
  }
}
