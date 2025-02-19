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

const int LM = 100005;

int N, M;
int A[LM], dp[LM];

int main( int argc, char **argv ) {
  scanf( "%d%d", &N, &M );
  dp[0] = 0;

  for ( int i = 1; i <= N; i++ ) {
    scanf( "%d", &A[i] );
    dp[i] = dp[i - 1] + A[i];
  }

  while ( M-- ) {
    int i, j;
    scanf( "%d%d", &i, &j );
    printf( "%d\n", dp[j] - dp[i - 1] );
  }
}
