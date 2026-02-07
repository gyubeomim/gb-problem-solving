#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    freopen("data/1076c.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, q;
        scanf("%d%d", &n, &q);

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

        vector<ll> best(n);

        for (int i = 0; i < n; ++i) 
					best[i] = max(a[i], b[i]);

        for (int i = n - 2; i >= 0; --i) 
					best[i] = max(best[i], best[i + 1]);

        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) 
					pref[i + 1] = pref[i] + best[i];

        for (int i = 0; i < q; ++i) {
            int l, r;
            scanf("%d%d", &l, &r);
            ll ans = pref[r] - pref[l - 1];
            printf("%lld ", ans);
        }
				puts("");
    }
}