#include <cstdio>

int N;
int A[100005];
int trr[100005];

void mergeSort(int s, int e) {
	if (s >= e) return;
	int m = (s + e) / 2;
	int i = s, j = m + 1, k = s;

	mergeSort(s, m); mergeSort(m + 1, e);

	while (i<=m && j<=e) {
		if (A[j] < A[i]) trr[k++] = A[j++];
		else trr[k++] = A[i++];
	}
	while (i <= m) trr[k++] = A[i++];
	while (j <= e) trr[k++] = A[j++];

	for (i = s; i <= e; i++) A[i] = trr[i];
	for (i = 0; i < N; i++) printf("%d ", A[i]);
	puts("");
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	mergeSort(0, N-1);
}

