#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

/*
	n: size of magazine
	h: health of your enemy
	k: time required to reload
*/

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/1081c.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
		while (T--) {
			int n;
			ll h, k;
			scanf("%d %lld %lld", &n, &h, &k);

			vector<ll> a(n + 1);
			ll sum = 0;
			for (int i = 1; i <= n; i++) {
					scanf("%lld", &a[i]);
					sum += a[i];
			}

			ll q = (h-1) / sum;      
			ll remain = h - q*sum;        

			vector<ll> pref(n + 1, 0);
			vector<ll> min_pref(n + 1, LLONG_MAX);

			for (int i = 1; i <= n; i++) {
					pref[i] = pref[i-1] + a[i];
					min_pref[i] = min(min_pref[i-1], a[i]);
			}

			vector<ll> max_suf(n+2, LLONG_MIN); 
			for (int i = n; i >= 1; i--) {
					max_suf[i] = max(max_suf[i + 1], a[i]);
			}

			int r = n; 
			for (int i = 1; i <= n; i++) {
					bool ok = (pref[i] >= remain);
					if (!ok && i < n) {
							ll best = pref[i] - min_pref[i] + max_suf[i + 1];
							if (best >= remain) ok = true;
					}
					if (ok) { r = i; break; }
			}

			ll ans = q*((ll)n + k) + r;
			printf("%lld\n", ans);
	}
}