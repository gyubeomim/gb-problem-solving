#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH( x ) cout << #x << " : " << x << '\n';
#define PRINT( x ) cout << x << '\n';
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int LM =10;

int N, M;
int arr[LM];
bool used[LM];

void solve( int k ) {
  if ( k == M ) {
    for ( int i = 0; i < M; i++ )
      printf( "%d ", arr[i] );
    puts( "" );
    return;
  }

  for ( int i = 1; i <= N; i++ ) {
    if ( !used[i] ) {
      arr[k] = i;
      used[i] = 1;
      solve( k + 1 );
      used[i] = 0;
    }
  }
}

int main( int argc, char **argv ) {
  scanf( "%d%d", &N, &M );
  solve( 0 );
}
