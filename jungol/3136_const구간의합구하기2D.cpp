#include <cstdio>
using ll = long long;

int N;
int A[1005][1005];
ll S[1005][1005];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];
		}
	}

	int M, sr, sc, er, ec;
	scanf("%d", &M);
	while (M--) {
		scanf("%d%d%d%d", &sr, &sc, &er, &ec);
		ll sum = S[er][ec] - S[sr - 1][ec] - S[er][sc - 1] + S[sr - 1][sc - 1];
		printf("%lld\n", sum);
	}
}

