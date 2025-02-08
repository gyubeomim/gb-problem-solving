#include <cstdio>

int heap[5000005];
int hn = 0;

void swap(int &a, int &b) {
	int t = a; a = b; b = t;
}

void push_heap(int nd) {
	heap[++hn] = nd;

	for (int c = hn; c > 1; c /= 2) {
		if (heap[c] > heap[c / 2])
			swap(heap[c], heap[c / 2]);
		else break;
	}
}

void pop_heap() {
	swap(heap[1], heap[hn--]);

	for (int c = 2; c <= hn; c *= 2) {
		if (c < hn && heap[c + 1] > heap[c]) c++;

		if (heap[c] > heap[c / 2]) swap(heap[c], heap[c / 2]);
		else break;
	}
}

int N;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int nd;
		scanf("%d", &nd);
		push_heap(nd);
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", heap[i]);
	}
	puts("");
	while (hn != 1) {
		pop_heap();
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", heap[i]);
	}
	puts("");
}

