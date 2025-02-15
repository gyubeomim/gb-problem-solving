#include <cstdio>

constexpr int LM = 100005;
int N, K;

struct Data {
	int x, d;
};

Data que[LM];
bool visit[LM];
int head, tail;

void bfs() {
	head = tail = 0;

	que[tail++] = { N, 0 };
	visit[N] = 1;

	while (head < tail) {
		int x = que[head].x;
		int d = que[head++].d;

		if (x == K) {
			printf("%d\n", d);
			return;
		}

		for (int i = 0; i < 3; i++) {
			int nx = x;
			if (i == 0) nx -= 1;
			else if (i == 1) nx += 1;
			else if (i == 2) nx *= 2;

			if (nx <0 || nx>LM) continue;
			if (visit[nx]) continue;

			visit[nx] = 1;
			que[tail++] = { nx, d+1 };
		}
	}

}

int main() {
	scanf("%d %d", &N, &K);

	bfs();
}

