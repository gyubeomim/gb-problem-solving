#include <cstdio>

int N, M;
int dice[10] = { 1 };

// 1. dice c를 채워라. c번째 주사위를 던져라 (중복순열)
void recur(int c) {
	// base case
	if (c == N + 1) {
		for (int i = 1; i <= N; i++)
			printf("%d ", dice[i]);
		printf("\n");
		return;
	}

	// normal case
	for (int i = 1; i <= 6; i++) {
		dice[c] = i;
		recur(c + 1);
	}
}

// 2. 중복조합 (앞선 값보다 현재값이 이상인 값이 나와야 함)
void recur2(int c) {
	if (c == N + 1) {
		for (int i = 1; i <= N; i++)
			printf("%d ", dice[i]);
		printf("\n");
		return;
	}

	// 앞선 값보다 현재값이 이상인 값이 나와야 함
	for (int i = dice[c - 1]; i <= 6; i++) {
		dice[c] = i;
		recur2(c + 1);
	}
}

// 3. 순열 (백트래킹 사용)
bool used[10];
void recur3(int c) {
	if (c == N + 1) {
		for (int i = 1; i <= N; i++)
			printf("%d ", dice[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= 6; i++) {
		if (used[i]) continue;

		dice[c] = i;

		// 백트래킹
		used[i] = 1;
		recur3(c + 1);
		used[i] = 0;
	}
}

int main() {
	scanf("%d%d", &N, &M);

	if(M==1)         recur(1);
	else if (M == 2) recur2(1);
	else if (M == 3) recur3(1);

	return 0;
}

