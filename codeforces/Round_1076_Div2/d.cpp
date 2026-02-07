#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

/*
  a[i] = i-th sword's strength
  b[i] = the number of strikes to beat the monster
*/

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
  freopen("data/1076d.txt", "r", stdin);
#endif
  int T; scanf("%d", &T);
  while(T--) {
    int n; scanf("%d", &n);

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
      scanf("%d", &a[i]);
    }

    vector<ll> pref(n);
    for(int i=0; i<n; i++){
      scanf("%d", &b[i]);
      pref[i] = (i == 0 ? b[i] : pref[i-1] + b[i]);
    }

    sort(a.begin(), a.end(), greater<int>());

    ll ans = 0;

    for(int m = 1; m <= n; m++){
      int x = a[m-1];
      int k = (int)(upper_bound(pref.begin(), pref.end(), m) - pref.begin());
      ll score = 1LL * x * k;
      if(score > ans) ans = score;
    }

    printf("%lld\n", ans);
  }
}