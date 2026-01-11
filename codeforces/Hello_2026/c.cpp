#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using namespace std;

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("data/d2026c.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while (T--) {
			int n, m, k;
			scanf("%d%d%d", &n, &m, &k);

			int leftCap = k - 1;
			int rightCap = n - k;

			int ans = 1; 

			//left
			for (int D = 1; D <= leftCap; D++) {
					int base = 2 * D - 1;
					if (base > m) break; 
					int rem = m - base;
					int Rmax = min({rightCap, D, rem});
					ans = max(ans, 1 + D + Rmax);
			}

			//right
			for (int D = 1; D <= rightCap; D++) {
					int base = 2 * D - 1;
					if (base > m) break;
					int rem = m - base;
					int Lmax = min({leftCap, D, rem});
					ans = max(ans, 1 + D + Lmax);
			}

			if (ans > n) ans = n;
			printf("%d\n", ans);
	}
}