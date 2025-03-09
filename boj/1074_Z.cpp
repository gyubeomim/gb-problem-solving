#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int solve( int n, int r, int c ) {
  if ( n == 0 ) return 0;
  int half = 1 << ( n - 1 );

  if ( r < half && c < half ) return solve( n - 1, r, c );
  if ( r < half && c >= half ) return half * half + solve( n - 1, r, c - half );
  if ( r >= half && c < half ) return 2 * half * half + solve( n - 1, r - half, c );
  return 3 * half * half + solve( n - 1, r - half, c - half );
}

int main( int argc, char **argv ) {
  int N, R, C;
  scanf( "%d%d%d", &N, &R, &C );

  int ret = solve( N, R, C );
  printf( "%d\n", ret );
}
