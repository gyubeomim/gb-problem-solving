#include <cstdio>

constexpr int LM = 105;
int N, used[10], ans;

struct Info {
	int A[6];
	bool isOK(int st = 0, int ba = 0) {
		for (int i = 0; i < 3; i++) {
			if (used[A[i]] == i) st++;		// 같은 자리에 사용된 경우
			else if (used[A[i]] > -1) ba++; // 같은 자리는 아니지만 사용된 경우
		}
		return A[3] == st && A[4] == ba;
	}
}info[LM];

void Permute(int step) {
	if (step >= 3) {
		for (int i = 0; i < N; i++) {
			if (info[i].isOK() == false) return;
		}
		ans++;
		return;
	}

	for (int i = 1; i < 10; i++) if (used[i] < 0) {
		used[i] = step;
		Permute(step + 1);
		used[i] = -1;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%1d", &info[i].A[j]);
		}
	}

	for (int i = 0; i < 10; i++) used[i] = -1;
	Permute(0);
	printf("%d\n", ans);

	return 0;
}
