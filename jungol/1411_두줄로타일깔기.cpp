#include <cstdio>

int dp[100005];

int main() {
	int N;
	scanf("%d", &N);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 2] * 2 + dp[i - 1] * 1)%20100529;
	}

	printf("%d", dp[N]);
}

