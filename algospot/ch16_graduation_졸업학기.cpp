#include <bits/stdc++.h>
using namespace std;

const int LM = 12;
const int INF = 987654321;
int N, K, M, L;

int prerequisite[LM];  // prerequisite[i] : i번째 과목의 선수과목의 집합
int classes[10];       // classes[i] : i번째 학기에 개설되는 과목의 집합
int dp[10][1 << LM];

// 켜진 비트의 수 반환
int bitCount( int x ) {
  if ( x == 0 ) return 0;
  return x % 2 + bitCount( x / 2 );
}

// 이번 학기가 semester이고 지금까지 들은 과목의 집합의 taken일 때
// k개 이상의 과목들을 모두 들으려면 몇 학기나 더 있어야 하는가?
// 불가능한 경우 INF를 반환한다
int graduate( int semester, int taken ) {
  if ( bitCount( taken ) >= K ) return 0;

  if ( semester == M ) return INF;

  int& ret = dp[semester][taken];
  if ( ret != -1 ) return ret;
  ret = INF;
	
	// 이번 학기에 들을 수 있는 과목 중 아직 듣지 않은 과목들을 찾기
  int canTake = ( classes[semester] & ~taken );
	
	// 선수 과목을 다 듣지 않은 과목들을 걸러낸다
  for ( int i = 0; i < N; i++ ) {
    if ( ( canTake & ( 1 << i ) ) &&
         ( taken & prerequisite[i] ) != prerequisite[i] )
      canTake &= ~( 1 << i );
  }
	
	// 이 집합의 모든 부분집합을 순회한다
  for ( int take = canTake; take > 0; take = ( ( take - 1 ) & canTake ) ) {
    if ( bitCount( take ) > L ) continue;  // 한 학기에 L과목까지만 들을 수 있다
    ret = min( ret, graduate( semester + 1, taken | take ) + 1 );
  }
	
	// 이번 학기에 아무것도 듣지 않을 경우
  ret = min( ret, graduate( semester + 1, taken ) );
  return ret;
}

int main( int argc, char** argv ) {
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d%d%d%d", &N, &K, &M, &L );

    memset( dp, -1, sizeof( dp ) );
    memset( prerequisite, 0, sizeof( prerequisite ) );
    memset( classes, 0, sizeof( classes ) );

    // 각 과목의 정보
    for ( int i = 0; i < N; i++ ) {
      int r;
      scanf( "%d", &r );
      for ( int j = 0; j < r; j++ ) {
        int temp;
        scanf( "%d", &temp );
        prerequisite[i] |= ( 1 << temp );
      }
    }
    // 각 학기의 정보
    for ( int i = 0; i < M; i++ ) {
      int t;
      scanf( "%d", &t );
      for ( int j = 0; j < t; j++ ) {
        int temp;
        scanf( "%d", &temp );
        classes[i] |= ( 1 << temp );
      }
    }

    int ans = graduate( 0, 0 );
    if ( ans == INF )
      printf( "IMPOSSIBLE\n" );
    else
      printf( "%d\n", ans );
  }
}
