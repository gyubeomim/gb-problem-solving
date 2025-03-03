#include <bits/stdc++.h>

const int MOD = 10000000;
const int LM = 105;

// dp[n][first] : n개의 정사각형을 포함하되, 첫 줄에 first개의 정사각형이 들어가는 폴리오미노 수
int dp[LM][LM];

// n개의 정사각형이 주어졌을 때 첫 가로줄이 first개의 정사각형을 포함하는 폴리오미노의 수를 반환하는 함수
// 시간복잡도: O(n^3) 
// n, first의 조합의 수 O(n^2), poly 계산 O(n)
int poly( int n, int first ) {
  if ( n == first ) return 1;

  int& ret = dp[n][first];
  if ( ret != -1 ) return ret;

  ret = 0;
  for ( int second = 1; second <= n - first; second++ ) {
    int add = ( second + first - 1 );
		add *= poly( n - first, second );
		add %= MOD;
		ret += add;
    ret %= MOD;
  }
  return ret;
}

int main( int argc, char** argv ) {
  int C;
  scanf( "%d", &C );

  while ( C-- ) {
    int N;
    scanf( "%d", &N );

    memset( dp, -1, sizeof( dp ) );

    int sum = 0;
    for ( int i = 1; i <= N; i++ ) {
      sum += poly( N, i );
			sum %= MOD;
    }
    printf( "%d\n", sum );
  }
}
