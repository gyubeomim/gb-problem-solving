#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>
#define X first
#define Y second

using namespace std;

using pii = pair<int, int>;

constexpr int LM = 105;
constexpr int NLM=LM*LM;

int R, C, Map[LM][LM];
int idcnt; // 노드 개수
int color; // 그래프 구성에서 현재 탐색중인 색(-1 or -2)
int ans = NLM;
int visited[NLM], vcnt;

const int dr[] = { -1,1,0,0 };
const int dc[] = { 0,0,-1,1 };

vector<int> adj[NLM];
unordered_set<int> adjCheck;
queue<pii> que;

void input() {
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			scanf("%d", Map[i] + j);
			// 1 -> -1, 0 -> -2로 바꾸어 처리 하기
			// 경계체크의 편의, 구역넘버링의 편의
			Map[i][j] -= 2;
		}
	}
}

void floodFill(int r, int c) {
	adjCheck.clear();
	que = {};
	Map[r][c] = ++idcnt;    // idcnt = (r,c)와 상하좌우로 연결된 구역의 노드 번호
	que.push({ r,c });

	while (!que.empty()) {
		pii t = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nr = t.X + dr[i];
			int nc = t.Y+ dc[i];

			int &child = Map[nr][nc];

			if (child == 0 || child == idcnt) continue;

			if (child == color) {
				child = idcnt;
				que.push({ nr,nc });
			}
			else if (child > 0 && adjCheck.count(child) == 0) {
				adjCheck.insert(child);

				adj[idcnt].push_back(child);
				adj[child].push_back(idcnt);
			}
		}
	}

}

void BFS(int source) {
	que = {};
	visited[source] = ++vcnt;
	que.push({ source,0 });

	int u, lv;

	while (!que.empty()) {
		u = que.front().X;
		lv = que.front().Y;
		que.pop();

		for (auto &v : adj[u]) {
			int nlv = lv + 1;
			if (visited[v] < vcnt) {
				visited[v] = vcnt;
				que.push({ v,nlv });
			}
		}
	}

	if (ans > lv) ans = lv;
}


int main() {
	input();

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (Map[i][j] < 0) {
				color = Map[i][j];
				floodFill(i, j);
			}
		}
	}

	for (int i = 1; i <= idcnt; i++) {
		BFS(i);
	}

	printf("%d", ans);

	return 0;
}
