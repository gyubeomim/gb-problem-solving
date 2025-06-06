#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int LM = 100005;
vector<int> A;
int N;

ll countMoves3( int s, int e ) {
  if ( s == e ) return 0;  // 기저 사례 : 구간의 길이가 1이라면 이미 정렬되었고 inversion도 없다

  int m = ( s + e ) / 2;
  ll ret = countMoves3( s, m ) + countMoves3( m + 1, e );

  vector<int> trr( e - s + 1 );
  int k = 0, i = s, j = m + 1;

  while ( i <= m || j <= e ) {
    if ( i <= m && ( j > e || A[i] <= A[j] ) ) {
      trr[k++] = A[i++];
    } else {
      // A[ridx]는 왼쪽 부분 배열에 남아 있는 모든 수보다 작다
      // 이 수들만큼 inversion을 더해준다
      ret += m - i + 1;
      trr[k++] = A[j++];
    }
  }
  for ( int i = 0; i < trr.size(); i++ ) A[s + i] = trr[i];
  return ret;
}

int main( int argc, char **argv ) {
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    A.clear();
    scanf( "%d", &N );
    for ( int i = 0; i < N; i++ ) {
      int a;
      scanf( "%d", &a );
      A.push_back( a );
    }
    ll ans = countMoves3( 0, A.size() - 1 );
    printf( "%lld\n", ans );
  }
}
