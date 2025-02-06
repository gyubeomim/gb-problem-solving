#include <cstdio>

int S;
int stairs[305];
int dp[305];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	scanf("%d", &S);
	for (int i = 1; i <= S; i++) {
		scanf("%d", &stairs[i]);
	}

	dp[0] = 0;
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];

	for (int i = 3; i <= S; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}

	printf("%d", dp[S]);
}

