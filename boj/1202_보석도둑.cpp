#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;
using ll = long long;

constexpr int LM = 300005;

int N, K;
pii jewel[LM];   // { 가격, 무게 }
multiset<int> bag;

int main() {
	scanf("%d%d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d%d", &jewel[i].Y, &jewel[i].X);
	}
	sort(jewel, jewel + N);

	for (int i = 0; i < K; i++) {
		int c;
		scanf("%d", &c);
		bag.insert(c);
	}

	ll ans = 0;

	for (int i = N - 1; i >= 0; i--) {
		int m, v;
		tie(v, m) = jewel[i];          // [ value, weight ]
		auto it = bag.lower_bound(m);  // 보석을 담을 수 있는 가방 중 최대 무게가 가장 작은 가방
		if (it == bag.end())continue;
		ans += v;
		bag.erase(it);
	}
	printf("%lld\n", ans);

}

