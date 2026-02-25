#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
  freopen("data/1077c.txt", "r", stdin);
#endif
  int T; scanf("%d", &T);
  while(T--) {
    int n; scanf("%d", &n);
    vector<ll> a(n), b;
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

    b = a;
    sort(b.begin(), b.end());

    if(a == b){ printf("-1\n"); continue; }

    ll mn = *min_element(a.begin(), a.end());
    ll mx = *max_element(a.begin(), a.end());

    ll ans = LLONG_MAX;
    for(int i=0; i<n; i++){
      if(a[i] != b[i]){
        ll v=a[i];
        ans = min(ans, max(v-mn, mx-v));
      }
    }
    printf("%lld\n", ans);
  }
}