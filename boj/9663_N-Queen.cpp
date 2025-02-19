#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

const int LM = 40;
bool used1[LM];   // column |
bool used2[LM];   // rtop diagonal /
bool used3[LM];   // ltop diagonal \

int cnt = 0;
int N;

void solve( int cur ) {
  if ( cur == N ) {
    cnt++;
    return;
  }

  for ( int i = 0; i < N; i++ ) {
    if ( used1[i] || used2[i + cur] || used3[cur - i + N - 1] ) continue;

    used1[i] = 1;
    used2[i + cur] = 1;
    used3[cur - i + N - 1] = 1;
    solve( cur + 1 );
    used1[i] = 0;
    used2[i + cur] = 0;
    used3[cur - i + N - 1] = 0;
  }
}

int main( int argc, char **argv ) {
  scanf( "%d", &N );
  solve( 0 );
  printf( "%d\n", cnt );
}
