#include <bits/stdc++.h>
#define X first
#define Y second
using pdd = std::pair<double, double>;
using namespace std;

const int INF = 987654321;
const int LM = 105;
const double pi = acos( -1 );

int N;
double y[LM], x[LM], r[LM];
pdd ranges[LM];  // 각 원이 덮이는 중심각의 구간

void convertToRange() {
  for ( int i = 0; i < N; i++ ) {
    double loc = fmod( 2 * pi + atan2( y[i], x[i] ), 2 * pi );
    double range = 2 * asin( 0.5 * r[i] / 8.0 );
    ranges[i] = make_pair( loc - range, loc + range );
  }
  // 각 구간을 시작위치가 작은 것부터 오게끔 정렬한다
  sort( ranges, ranges + N );
}

// [begin, end] 구간을 덮기 위해 선택할 최소한의 구간 수를 반환하는 함수
// ranges는 시작 위치의 오름차순으로 정렬되어 있다고 가정
int solveLinear( double begin, double end ) {
  int used = 0, idx = 0;

  // 덮지 못한 선분이 남아있는 동안 반복한다
  while ( begin < end ) {
    // begin보다 이전에 시작하는 구간 중 가장 늦게 끝나는 구간을 찾는다
    double maxCover = -1;
    while ( idx < N && ranges[idx].X <= begin ) {
      maxCover = max( maxCover, ranges[idx].Y );
      ++idx;
    }
    // 덮을 구간을 찾지 못한 경우
    if ( maxCover <= begin ) return INF;
    // 선분이 덮인 부분을 잘라낸다
    begin = maxCover;
    ++used;
  }
  return used;
}

// 0을 덮을 구간을 선택하고 나머지를 선형으로 푼다
int solveCircular() {
  int ret = INF;
  // 각 구간을 시작 위치의 오름차순으로 정렬한다
  sort( ranges, ranges + N );

  // 0을 덮을 구간을 선택
  for ( int i = 0; i < N; i++ ) {
    if ( ranges[i].X <= 0 || ranges[i].Y >= 2 * pi ) {
      // 이 구간이 덮는 부분을 빼고 남는 중심각의 범위는 다음과 같다
      double begin = fmod( ranges[i].Y, 2 * pi );
      double end = fmod( ranges[i].X + 2 * pi, 2 * pi );
      // [begin, end] 선분을 주어진 구간을 사용해서 덮는다
      ret = min( ret, 1 + solveLinear( begin, end ) );
    }
  }
  return ret;
}

int main( int argc, char **argv ) {
  int C;
  scanf( "%d", &C );

  while ( C-- ) {
    scanf( "%d", &N );
    for ( int i = 0; i < N; i++ ) {
      scanf( "%lf%lf%lf", &y[i], &x[i], &r[i] );
    }
    convertToRange();
    int ret = solveCircular();
    if ( ret == INF )
      printf( "IMPOSSIBLE\n" );
    else
      printf( "%d\n", ret );
  }
}
