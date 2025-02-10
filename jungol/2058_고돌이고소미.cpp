#include <cstdio>

int N;

struct Data {
	int x, y;
};

Data A, Ahome;
Data B, Bhome;

struct Data2 {
	int x1, y1, x2, y2, t;
};

Data2 que[30 * 30 * 30 * 30];
int visit[30][30][30][30];
int head, tail;

int board[30][30];

int dx[9] = { 0, -1, 1, -1, 1, 0, 0, -1, 1 };
int dy[9] = { 0, -1, 1, 1, -1, -1, 1, 0, 0 };
//            5   1  9  7   3  2  8  4  6

int abs(int a) { return a > 0 ? a : -a; }

bool isAdj(int x1, int y1, int x2, int y2) {
	if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) return true;
	return false;
}

void bfs() {
	head = tail = 0;

	que[tail++] = { A.x, A.y, B.x, B.y, 0 };
	visit[A.x][A.y][B.x][B.y] = 1;

	while (head < tail) {
		Data2 cur = que[head++];
		
		int x1 = cur.x1;
		int y1 = cur.y1;

		int x2 = cur.x2;
		int y2 = cur.y2;

		if (x1 == Ahome.x 
			&& y1 == Ahome.y 
			&& x2 == Bhome.x 
			&& y2 == Bhome.y) 
		{
			printf("%d\n", cur.t);
			return;
		}

		for (int d1 = 0; d1 < 9; d1++) {
			for (int d2 = 0; d2 < 9; d2++) {
				if (d1 == 0 && d2 == 0) continue;

				int nx1 = cur.x1 + dx[d1];
				int ny1 = cur.y1 + dy[d1];

				int nx2 = cur.x2 + dx[d2];
				int ny2 = cur.y2 + dy[d2];

				if (nx1 < 1 || nx1 > N  || ny1 < 1 || ny1 > N ) continue;
				if (nx2 < 1 || nx2 > N  || ny2 < 1 || ny2 > N ) continue;
				if (board[nx1][ny1] == 1) continue;
				if (board[nx2][ny2] == 1) continue;
				if (isAdj(nx1, ny1, nx2, ny2)) continue;
				if (visit[nx1][ny1][nx2][ny2]) continue;

				visit[nx1][ny1][nx2][ny2] = true;
				que[tail++] = { nx1, ny1, nx2, ny2, cur.t + 1 };
			}
		}
	}

}

int main() {
	scanf("%d", &N);

	int a,b,c,d;
	scanf("%d %d %d %d", &a, &b, &c, &d); A.x = a; A.y = b; Ahome.x = c; Ahome.y = d;
	scanf("%d %d %d %d", &a, &b, &c, &d); B.x = a; B.y = b; Bhome.x = c; Bhome.y = d;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d ", &board[i][j]);
		}
	}

	bfs();
}

