#include <cstdio>

int M, S, C;
int cows[205];
int interdist[205];

int trr[205];

void mergeSort(int* arr, int s, int e) {
	if (s >= e)return;

	int m = (s + e) / 2;
	int i = s, j = m + 1, k = s;

	mergeSort(arr, s, m); mergeSort(arr, m + 1, e);

	while (i <= m && j <= e) {
		if (arr[i] < arr[j]) trr[k++] = arr[i++];
		else trr[k++] = arr[j++];
	}
	while (i <= m) trr[k++] = arr[i++];
	while (j <= e) trr[k++] = arr[j++];

	for (i = s; i <= e; i++) arr[i] = trr[i];
}

int main() {
	scanf("%d %d %d", &M, &S, &C);
	for (int i = 0; i < C; i++) {
		scanf("%d", &cows[i]);
	}

	mergeSort(cows, 0, C - 1);

	int sum = cows[C - 1] - cows[0] + 1;            // 전체 길이

	int N = 0;

	for (int i = 1; i < C; i++) {
		interdist[N++] = cows[i] - cows[i - 1] - 1;    // -1 빼줘야 함 (두 외양간 사이의 거리이므로)
	}

	mergeSort(interdist, 0, N - 1);

	for (int i = N-1; i >= 0; i--) {
		if (--M == 0) break;
		sum -= interdist[i];
	}

	printf("%d\n", sum);
}

