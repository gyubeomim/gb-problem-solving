#include <cstdio>

int abs(int a) { return a > 0 ? a : -a; }
int min(int a, int b) { return a > b ? b : a; }

int N, S[10], B[10];
int ans = 1e9;
int used[15];

void recur(int n) {
	if (n == N) {
		if (N == 1) ans = abs(S[0] - B[0]);
		return;
	}

	int Ssum = 1, Bsum = 0;

	for (int i = 0; i < N; i++) {
		if (used[i]) continue;

		Ssum *= S[i];
		Bsum += B[i];

		ans = min(ans, abs(Ssum - Bsum));

		used[i] = 1;
		recur(n + 1);
		used[i] = 0;
	}

}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &S[i], &B[i]);
	}

	recur(1);

	printf("%d", ans);
}

