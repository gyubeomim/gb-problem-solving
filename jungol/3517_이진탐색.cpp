#include <cstdio>

int N,Q;
int A[500005];

int binarySearch(int x) {
	int s = 0, e = N - 1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (A[mid] < x) s = mid + 1;
		else e = mid - 1;

		if (A[mid] == x) return mid;
	}
	return -1;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);
		printf("%d ", binarySearch(q));
	}

}

