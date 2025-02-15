#include <cstdio>

int total;

int N, M, H;
int A[105][105][105];

struct Data {
	int r, c, h, d;
} que[105*105*105];

int head, tail;

int dr[6] = { -1,1,0,0,0,0 };
int dc[6] = { 0,0,-1,1,0,0 };
int dh[6] = { 0,0,0,0,-1,1 };

void bfs() {
	while (head < tail) {
		Data cur = que[head++];

		for (int d = 0; d < 6; d++) {
			int nr = cur.r + dr[d];
			int nc = cur.c + dc[d];
			int nh = cur.h + dh[d];

			if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1 || nh < 0 || nh > H-1) continue;
			if (A[nr][nc][nh] != 0) continue;

			que[tail++] = { nr, nc, nh, cur.d + 1 };
			A[nr][nc][nh] = 1;
		}
	}

	if (tail != total)  printf("-1\n");
	else  printf("%d\n", que[tail - 1].d);

}

int main() {
	scanf("%d %d %d", &M, &N, &H);
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &A[i][j][h]);
				if (A[i][j][h] == 1) {
					que[tail++] = { i,j,h,0 };
				}
				if (A[i][j][h] != -1) {
					total++;
				}
			}
		}
	}

	bfs();
}

