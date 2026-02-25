#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

int main() {
#ifndef ONLINE_JUDGE
  freopen("data/1076f.txt", "r", stdin);
#endif

  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    ll Ax, Ay, Bx, By;
    scanf("%d%lld%lld%lld%lld", &n, &Ax, &Ay, &Bx, &By);

    vector<ll> xs(n), ys(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &xs[i]);
    for (int i = 0; i < n; ++i) scanf("%lld", &ys[i]);

    vector<pll> v;
    v.reserve(n);

    for (int i = 0; i < n; ++i) 
			v.push_back({xs[i], ys[i]});
    sort(v.begin(), v.end());

    vector<pll> seg; 
    seg.reserve(n);

    for (int i = 0; i < n; ) {
      int j = i;
      ll lo = v[i].Y, hi = v[i].Y;
      while (j < n && v[j].X == v[i].X) {
        lo = min(lo, v[j].Y);
        hi = max(hi, v[j].Y);
        ++j;
      }
      seg.push_back({lo, hi});
      i = j;
    }

    ll dp0 = 0, dp1 = 0;
    ll prevLo = seg[0].X, prevHi = seg[0].Y;
    ll span = prevHi - prevLo;
    dp0 = span + llabs(Ay - prevHi); 
    dp1 = span + llabs(Ay - prevLo); 

    for (int k = 1; k < seg.size(); ++k) {
      ll lo = seg[k].X, hi = seg[k].Y;
      ll s = hi - lo;

      ll ndp0 = s + min(dp0 + llabs(prevLo - hi), dp1 + llabs(prevHi - hi)); 
      ll ndp1 = s + min(dp0 + llabs(prevLo - lo), dp1 + llabs(prevHi - lo)); 

      dp0 = ndp0; 
			dp1 = ndp1;
      prevLo = lo; 
			prevHi = hi;
    }

    ll vert = min(dp0 + llabs(prevLo - By), dp1 + llabs(prevHi - By));
    ll ans = (Bx - Ax) + vert;
    printf("%lld\n", ans);
  }
}