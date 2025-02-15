#include <cstdio>

int N, K;
int s, e;
char A[1005][35];

struct Data {
	int id, dist;
};
Data que[1005];
bool visit[1005];
int head, tail;

int Prev[1005];

bool isAdj(char a[], char b[]) {
	int diff = 0;

	for (int i = 0; i < K; i++) {
		if (a[i] != b[i]) diff++;
		if (diff > 1) return false;
	}

	return true;
}

void trace(int id) {
	if (id == 0) { return; }

	trace(Prev[id]);
	printf("%d ", id);
}

void bfs() {
	head = tail = 0;

	que[tail++] = { s,0 };
	visit[s] = 1;

	while (head < tail) {
		Data cur = que[head];

		if (cur.id == e) {
			trace(e);
			return;
		}

		for (int i = 1; i <= N; i++) {
			if (visit[i]) continue;
			if (!isAdj(A[cur.id], A[i])) continue;

			que[tail++] = { i, cur.dist + 1 };
			visit[i] = 1;
			Prev[i] = cur.id;
		}
		head++;
	}
	printf("-1\n");
}

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%s", A[i]);
	}

	scanf("%d %d", &s, &e);

	bfs();
}


