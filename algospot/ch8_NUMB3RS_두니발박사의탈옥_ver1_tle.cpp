// #1 완전탐색 (TLE)
#include <bits/stdc++.h>
using namespace std;

const int LM = 55;

int N,D,P,Q;
int connected[LM][LM];
int deg[LM];
// connected[i][j] = 마을 i,j의 연결 여부
// deg[i] = 마을 i와 연결된 마을의 개수


double search( vector<int>& path ) {
  if ( path.size() == D + 1 ) {
    if ( path.back() != Q ) return 0.0;  // 이 시나리오가 Q에서 끝나지 않는다면 무효

    // path의 출현 확률 계산
    double ret = 1.0;
    for ( int i = 0; i < path.size() - 1; i++ )
      ret /= deg[path[i]];
    return ret;
  }

  double ret = 0;
  // 경로의 다음 위치 결정
  for ( int there = 0; there < N; there++ ) {
    if ( connected[path.back()][there] ) {
      path.push_back( there );
      ret += search( path );
      path.pop_back();
    }
  }
  return ret;
}

int main( int argc, char** argv ) {
  int C;
  scanf( "%d", &C );

  while ( C-- ) {
    scanf( "%d%d%d", &N, &D, &P );

    memset( connected, 0, sizeof( connected ) );
    memset( deg, 0, sizeof( deg ) );

    for ( int i = 0; i < N; i++ ) {
      for ( int j = 0; j < N; j++ ) {
        scanf( "%d ", &connected[i][j] );
        if ( connected[i][j] ) deg[i]++;
      }
    }

    int T;
    scanf( "%d", &T );
    for ( int i = 0; i < T; i++ ) {
      scanf( "%d", &Q );
      vector<int> path;
      path.push_back( P );
      printf( "%.8lf ", search( path ) );
    }
    puts( "" );
  }
}
