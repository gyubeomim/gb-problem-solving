#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;

constexpr int MOD = (int)1e9;
constexpr int LM = 100005;

int N, M;

struct Data {
	int from, to, w;
} G[LM];

int P[LM];
int num[LM];

ll sum = 0;
ll ans = 0;

int Find(int n) {
	if (P[n] == n) return n;
	return P[n] = Find(P[n]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	/*printf("ans %lld = ans %lld + sum %lld * num[%d]: %d * num[%d]: %d\n",
		(ans + sum * num[a] * num[b]) % MOD, ans, sum, a, num[a], b, num[b]);*/

	ans = (ans + sum * num[a] * num[b]) % MOD;

	P[a] = b;
	num[b] += num[a];
}

int main() {
#ifdef _WIN32
	freopen("31.txt", "r", stdin);
#endif // _WIN32

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		P[i] = i;
		num[i] = 1;
	}

	for (int i = 0; i < M; i++) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);

		G[i] = { x,y,w };
		sum += w;
	}

	sort(G, G + M, [](const Data&a, Data&b) {
		return a.w > b.w;
	});

	for (int i = 0; i < M; i++) {
		Union(G[i].from, G[i].to);
		sum -= G[i].w;
	}

	printf("%lld", ans);

	return 0;
}

