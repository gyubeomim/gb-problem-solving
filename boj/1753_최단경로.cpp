#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

constexpr int LM = 20005;
constexpr int INF = 0x3f3f3f3f;

vector<pii> adj[LM];
priority_queue<pii, vector<pii>, greater<pii>> pq;

bool fix[LM];
int d[LM];
int V, E, K;

void dijkstra(int s) {
	fill(d, d + V + 1, INF);
	d[s] = 0;

	// 우선순위 큐에 (0, 시작점) 추가
	pq.push({ d[s], s });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (d[cur.Y] != cur.X) continue;

		for (auto next : adj[cur.Y]) {
			if (d[next.Y] <= d[cur.Y] + next.X) continue;
			d[next.Y] = d[cur.Y] + next.X;
			pq.push({ d[next.Y], next.Y });
		}
	}
}


int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);


	while (E--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({ w,v });
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) printf("INF\n");
		else printf("%d\n", d[i]);
	}
}

