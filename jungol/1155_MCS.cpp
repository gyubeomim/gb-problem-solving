#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int LM = 60005;
int N, K;
int ans;
int A[LM];
char str[LM];
unordered_map<ll, int> hmap;

int w[] = { 1, 1001, 1001 * 1001, 1001 * 1001 * 1001 };

int main( int argc, char **argv ) {
  scanf( "%d%s", &K, str );
  ll key = 0;

  int i, j;
  for ( i = 0; str[i]; i++ ) {
    if ( str[i] == 'A' )
      A[i] = w[0];
    else if ( str[i] == 'C' )
      A[i] = w[1];
    else if ( str[i] == 'G' )
      A[i] = w[2];
    else
      A[i] = w[3];
  }

  N = i;
  for ( i = 0; i <= N - K; i++ ) {
    key = 0;
    for ( j = i; j < i + K; j++ ) {
      key += A[j];
    }
    ans = max( ans, ++hmap[key] );
  }
  printf( "%d\n", ans );
}
