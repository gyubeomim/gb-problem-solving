#include <bits/stdc++.h>
using namespace std;

const int LM = 10000000;

int factors[LM + 1]; 

// 시간복잡도: O(nlogn)
void getFactorsBrute() {
  memset( factors, 0, sizeof( factors ) );
  for ( int div = 1; div <= LM; div++ ) {
    for ( int mult = div; mult <= LM; mult += div )
      factors[mult] += 1;
  }
}

int main( int argc, char **argv ) {
  getFactorsBrute();

  int C;
  scanf( "%d", &C );

  while ( C-- ) {
    int N, lo, hi;
    scanf( "%d%d%d", &N, &lo, &hi );

    int ans = 0;
    for ( int i = lo; i <= hi; i++ ) {
      if ( factors[i] == N )
        ans++;
    }
    printf( "%d\n", ans );
  }
}
