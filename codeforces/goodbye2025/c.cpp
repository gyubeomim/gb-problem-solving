#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 200005;

static ll A[LM];

int main( int argc, char** argv ) {
#ifndef ONLINE_JUDGE
  freopen("data/d2992.txt", "r", stdin);
#endif

  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);

    ll total = 0;
    for(int i=1; i<=N; i++) {
      scanf("%lld", &A[i]);
      total += A[i];
    }

    vector<ll> prefix(N+1, 0);
    for(int i=2; i<=N; i++) {
      prefix[i] = prefix[i-1] + max(0ll, A[i]);
    }

    ll ans = LLONG_MIN;

    for(int k=1; k<=N; k++) {
      ll extra = 0;
      if (k>1) extra += 2*A[1];
      extra += 2*prefix[k-1];
      ll x = -total + A[k] + extra;
      ans = max(ans, x);
    }
    printf( "%lld\n", ans );
  }
}