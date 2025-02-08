#include <cstdio>

constexpr int INF = 70000;

int N, W;
int A[15];
int dp[64005];

int min(int a, int b) { return a > b ? b : a; }

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d",&A[i]);
	}

	scanf("%d", &W);

	dp[0] = 0;
	for (int i = 1; i <= W; i++) {
		dp[i] = INF;

		for (int j = 0; j < N; j++) {
			if (i - A[j] < 0) continue;
			dp[i] = min(dp[i], dp[i - A[j]] + 1);
		}
	}

	if (dp[W] == INF) printf("impossible\n");
	else printf("%d\n", dp[W]);
}

