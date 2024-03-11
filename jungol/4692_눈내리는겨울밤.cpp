#include <cstdio>
int N, Q;
using ll = long long;
constexpr int LM = (int)1e3 + 5;

ll A[LM][LM];
ll S[LM][LM];

int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < Q; i++) {
		int sr, sc, er, ec, val;
		scanf("%d %d %d %d %d", &sr, &sc, &er, &ec, &val);

		A[sr][sc] += val;
		A[sr][ec + 1] -= val;
		A[er + 1][sc] -= val;
		A[er + 1][ec + 1] += val;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (j - 1 < 0 && i - 1 < 0) {
				S[i][j] = A[i][j];
			}
			else if (j - 1 < 0) {
				S[i][j] = S[i - 1][j] + A[i][j];
			}
			else if (i - 1 < 0) {
				S[i][j] = S[i][j - 1] + A[i][j];
			}
			else {
				S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%lld ", S[i][j]);
		}
		puts("");
	}

	return 0;
}
