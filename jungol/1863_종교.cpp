#include <cstdio>

constexpr int LM = 50005;
int N, M, ret;
int root[LM];

int Find(int n) {
	if (n == root[n]) return n;
	return root[n] = Find(root[n]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);
	if (a == b) return;
	ret--;
	root[b] = a;
}


int main() {
	scanf("%d %d", &N, &M);
	ret = N;
	for (int i = 1; i <= N; i++) {
		root[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		Union(a, b);
	}

	printf("%d", ret);


	return 0;
}

