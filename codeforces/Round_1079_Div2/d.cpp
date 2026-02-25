#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    freopen("data/1079d.txt", "r", stdin);
#endif

    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        int B = (int)std::sqrt(n) + 1;
        ll ans = 0;

        for (int i = 1; i <= n; i++) {
            ll x = a[i];

            if (x <= B) {
                for (ll q = 1; q <= B; q++) {
                    ll d = x * q;
                    int j = i + (int)d;
                    if (j > n) break;
                    if (a[j] == q) ans++;
                }
            } else {
                ll ymax = (n - 1) / x;
                for (ll y = 1; y <= ymax; y++) {
                    ll d = x * y;

                    int r = i + (int)d; 
                    if (r <= n && a[r] == y) ans++;

                    int l = i - (int)d; 
                    if (l >= 1 && a[l] == y) ans++;
                }
            }
        }
				printf("%lld\n", ans);
    }
}