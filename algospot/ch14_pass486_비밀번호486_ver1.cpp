#include <bits/stdc++.h>
using namespace std;

const int LM = 10000000;

int minFactor[LM + 1];       // minFactor[i] : i의 가장 작은 소인수(i가 소수인 경우 자기 자신)
int minFactorPower[LM + 1];  // minFactorPower[i] : i의 소인수 분해에는 minFactor[i]의 몇 승이 포함되어 있는가?
int factors[LM + 1];         // factors[i] : i가 가진 약수의 수
// factor[i] = factor[i/p] * (a+1)/a;
// p : n의 가장 작은 소인수

void eratosthenes( int n ) {
  minFactor[0] = minFactor[1] = -1;
  for ( int i = 2; i <= n; i++ )
    minFactor[i] = i;

  for ( int i = 2; i * i <= n; i++ ) {
    if ( minFactor[i] == i )
      for ( int j = i * i; j <= n; j += i )
        if ( minFactor[j] == j )
          minFactor[j] = i;
  }
}

void getFactorsSmart() {
  factors[1] = 1;

  for ( int i = 2; i <= LM; i++ ) {
    if ( minFactor[i] == i ) {  // i이 소수인 경우
      minFactorPower[i] = 1;
      factors[i] = 2;
    } else {  // i이 소수가 아닌 경우
      int p = minFactor[i];
      int m = i / p;
      // m이 p로 더이상 나누어지지 않는 경우
      if ( p != minFactor[m] )
        minFactorPower[i] = 1;
      else
        minFactorPower[i] = minFactorPower[m] + 1;
      int a = minFactorPower[i];
      factors[i] = ( factors[m] / a ) * ( a + 1 );
    }
  }
}

int main( int argc, char **argv ) {
  eratosthenes( LM );
  getFactorsSmart();

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
