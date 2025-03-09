#include <bits/stdc++.h>
using namespace std;

int N;

int gcd( int a, int b ) {
  return b == 0 ? a : gcd( b, a % b );
}

int ceil( int a, int b ) {
  return ( a + b - 1 ) / b;
}

vector<int> solve2( vector<int> recipe, vector<int> put ) {
  int b = recipe[0];

  for ( int i = 1; i < N; i++ ) b = gcd( b, recipe[i] );

  int a = b;

  for ( int i = 0; i < N; i++ ) {
    a = max( a, ceil( put[i] * b, recipe[i] ) );
  }

  vector<int> ret;
  for ( int i = 0; i < N; i++ ) {
    ret[i] = recipe[i] * a / b - put[i];
  }

  return ret;
}

int main( int argc, char **argv ) {
  int C;
  scanf( "%d", &C );

  while ( C-- ) {
    scanf( "%d", &N );

    vector<int> recipe, put;

    for ( int i = 0; i < N; i++ ) {
      int a;
      scanf( "%d", &a );
      recipe.push_back( a );
    }

    for ( int i = 0; i < N; i++ ) {
      int a;
      scanf( "%d", &a );
      put.push_back( a );
    }

    vector<int> ret = solve2( recipe, put );

    for ( auto &e : ret ) {
      printf( "%d ", e );
    }
    puts( "" );
  }
}
