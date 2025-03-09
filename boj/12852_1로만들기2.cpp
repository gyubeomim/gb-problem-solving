#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM=1000005;

int dp[LM], pre[LM];
int N;

int main( int argc, char **argv ) {
  scanf( "%d", &N );

  dp[1] = 0;
  for ( int i = 2; i <= N; i++ ) {
    dp[i] = dp[i - 1] + 1;
    pre[i] = i - 1;

    if ( i % 2 == 0 && dp[i] > dp[i / 2] + 1 ) {
      dp[i] = dp[i / 2] + 1;
      pre[i] = i / 2;
    }
    if ( i % 3 == 0 && dp[i] > dp[i / 3] + 1 ) {
      dp[i] = dp[i / 3] + 1;
      pre[i] = i / 3;
    }
  }
  printf( "%d\n", dp[N] );

  int cur = N;
  while ( 1 ) {
    printf( "%d ", cur );
    if ( cur == 1 ) break;
    cur = pre[cur];
  }
}
