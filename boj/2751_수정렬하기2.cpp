#include <bits/stdc++.h>

constexpr int LM = 1'000'005;
int N;
int arr[LM];

int trr[LM];
void mergeSort( int s, int e ) {
  if ( s >= e ) return;
  int m = ( s + e ) / 2;
  mergeSort( s, m );
  mergeSort( m + 1, e );

  int i = s, j = m + 1, k = s;

  while ( i <= m && j <= e ) {
    if ( arr[i] < arr[j] )
      trr[k++] = arr[i++];
    else
      trr[k++] = arr[j++];
  }
  while ( i <= m )
    trr[k++] = arr[i++];
  while ( j <= e )
    trr[k++] = arr[j++];

  for ( i = s; i <= e; i++ ) arr[i] = trr[i];
}

int main( int argc, char **argv ) {
  scanf( "%d", &N );

  for ( int i = 0; i < N; i++ ) {
    scanf( "%d", arr + i );
  }

  mergeSort( 0, N - 1 );

  for ( int i = 0; i < N; i++ ) {
    printf( "%d\n", arr[i] );
  }
}
