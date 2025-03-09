#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int LM = 100005;

int N;
ll A[LM];

int main( int argc, char **argv ) {
  scanf( "%d", &N );
  for ( int i = 0; i < N; i++ )
    scanf( "%lld", A + i );

  sort( A, A + N );

  int cnt = 0;
  ll mxval = -( 1ll << 62 ) - 1;
  int mxcnt = 0;

  for ( int i = 0; i < N; i++ ) {
    if ( i == 0 || A[i - 1] == A[i] )
      cnt++;
    else {
      if ( cnt > mxcnt ) {
        mxcnt = cnt;
        mxval = A[i - 1];
      }
      cnt = 1;
    }
  }

  if ( cnt > mxcnt ) mxval = A[N - 1];
  printf( "%lld\n", mxval );
}
