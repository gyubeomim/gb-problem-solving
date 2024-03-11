#include <cstdio>

int A[12];
int x, K;

int main() {
	scanf("%d", &K);

	int d;
	for (int i = 0; i < 6; i++) {
		scanf("%*d %d", A + i);
		A[i + 6] = A[i];
		if (A[x] < A[i]) x = i;
	}

	printf("%d\n", (A[x + 1] * A[x + 2] + A[x + 4] * A[x + 5])*K);


	return 0;
}
