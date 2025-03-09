#include <bits/stdc++.h>

const int LM=1005;
const int MOD=10007;

int dp[LM];
int N;

int main( int argc, char **argv ) {
  scanf( "%d", &N );

  dp[1] = 1;
  dp[2] = 2;
  for ( int i = 3; i <= N; i++ ) {
    dp[i] = ( dp[i - 1] + dp[i - 2] ) % MOD;
  }
  printf( "%d\n", dp[N] );
}
