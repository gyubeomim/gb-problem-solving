#include <bits/stdc++.h>
using namespace std;

const int LM = 1005;
int dp[LM][3];
int N;

int main( int argc, char **argv ) {
  scanf( "%d", &N );

  for ( int i = 0; i < N; i++ ) {
    int r, g, b;
    scanf( "%d%d%d", &r, &g, &b );

    if ( i == 0 ) {
      dp[i][0] = r;
      dp[i][1] = g;
      dp[i][2] = b;
    } else {
      dp[i][0] = min( dp[i - 1][1], dp[i - 1][2] ) + r;
      dp[i][1] = min( dp[i - 1][0], dp[i - 1][2] ) + g;
      dp[i][2] = min( dp[i - 1][0], dp[i - 1][1] ) + b;
    }
  }

  int ans = min( dp[N - 1][0], dp[N - 1][1] );
  ans = min( ans, dp[N - 1][2] );

  printf( "%d\n", ans );
}
