#include <cstdio>
#include <algorithm>

int N;
int A[3005], S[3005];
int tcost, hcost;
int dp[3005];    // d[i] = i 지점까지 트럭과 헬기를 이용할 때 최소 비용

int min(int a, int b) { return a > b ? b : a; }

int getCost(int s, int e) {
	int m = (s + e) / 2;
	int sdist = A[m] * (m - s + 1) - (S[m] - S[s - 1]);
	int edist = (S[e] - S[m]) - A[m] * (e - m);
	return (sdist + edist) * tcost;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {   // 1-base
		scanf("%d", A + i);
	}

	scanf("%d %d", &tcost, &hcost);

	// 정렬
	std::sort(A + 1, A + 1 + N);

	// prefix sum
	for (int i = 1; i <= N; i++) {
		S[i] = S[i - 1] + A[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + A[i] * tcost;                              // i 지점에 본점에서 트럭으로 이동
		
		for (int j = 1; j <= i; j++) {                                 // [j,i] 지점을 한 개의 헬기로 이동
			dp[i] = min(dp[i], dp[j - 1] + getCost(j, i) + hcost);       // 1 <= j <= i
		}
	}

	printf("%d\n", dp[N]);
}

