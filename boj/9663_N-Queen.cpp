#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

const int LM = 40;
bool used1[LM];  // column |
bool used2[LM];  // rtop diagonal /
bool used3[LM];  // ltop diagonal \

int cnt = 0;
int N;

void solve( int r ) {
  if ( r == N ) {
    cnt++;
    return;
  }

  for ( int c = 0; c < N; c++ ) {
    if ( used1[c] || used2[r + c] || used3[r - c + N - 1] ) continue;

    used1[c] = 1;
    used2[c + r] = 1;
    used3[r - c + N - 1] = 1;
    solve( r + 1 );
    used1[c] = 0;
    used2[c + r] = 0;
    used3[r - c + N - 1] = 0;
  }
}

int main( int argc, char **argv ) {
  scanf( "%d", &N );
  solve( 0 );
  printf( "%d\n", cnt );
}
