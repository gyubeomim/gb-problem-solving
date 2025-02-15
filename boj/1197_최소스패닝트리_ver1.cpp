#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

constexpr int LM = 10005;

vector<pii> adj[LM];  // adj[i] = { cost , vertex_id }

bool chk[LM]; // chk[i] : i번째 정점이 MST에 속해있는가?
int cnt = 0;  // 현재 선택된 간선의 수

int main() {
	int v, e;
	scanf("%d%d", &v, &e);

	for (int i = 0; i < e; i++) {
		int a, b, cost;
		scanf("%d%d%d", &a, &b, &cost);
		adj[a].push_back({ cost,b });
		adj[b].push_back({ cost,a });
	}

	// Prim algorithm (using pq)
	priority_queue<tiii, vector<tiii>, greater<tiii>> pq;   // pq[i] = { cost, vertex_id1, vertex_id2 }

	chk[1] = 1;

	for (auto nxt : adj[1]) {
		pq.push({ nxt.X, 1, nxt.Y });
	}

	int ans = 0;

	while (cnt < v - 1) {
		int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();

		if (chk[b]) continue;

		ans += cost;
		chk[b] = 1;
		cnt++;

		for (auto nxt : adj[b]) {
			if (!chk[nxt.Y])
				pq.push({ nxt.X,b,nxt.Y });
		}
	}
	printf("%d\n", ans);
}

