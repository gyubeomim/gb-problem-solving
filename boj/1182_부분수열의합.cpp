#include <bits/stdc++.h>

#define rnt register int
using namespace std;

using pii = pair<int,int>;
using ll = long long;

constexpr int LM = 30;
int arr[LM] = { 0 };
int visited[LM] = { 0 };
int ans = 0;
int N, S;

void solve( int idx, int tot ) {
  if ( idx == N ) {
    if ( tot == S ) ans++;
    return;
  }

  solve( idx + 1, tot );             // 현재 원소를 더하지 않을 때
  solve( idx + 1, tot + arr[idx] );  // 현재 원소를 더할 때
}

int main( int argc, char **argv ) {
  scanf( "%d %d", &N, &S );
  for ( int i = 0; i < N; i++ )
    scanf( "%d", &arr[i] );

  solve( 0, 0 );
  if ( S == 0 ) ans--;
  printf( "%d", ans );
}
