#include <bits/stdc++.h>
using namespace std;

vector<int> men;
int N, K;

int main( int argc, char **argv ) {
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d%d", &N, &K );

    men.clear();

    for ( int i = 1; i <= N; i++ ) {
      men.push_back( i );
    }

    auto it = men.erase( men.begin() );
    int cur = std::distance( men.begin(), it );

    while ( men.size() > 2 ) {
      int target = ( cur + K - 1 ) % ( men.size() );
      it = men.erase( men.begin() + target );
      cur = std::distance( men.begin(), it );
    }

    for ( auto e : men ) {
      printf( "%d ", e );
    }
    puts( "" );
  }
}
