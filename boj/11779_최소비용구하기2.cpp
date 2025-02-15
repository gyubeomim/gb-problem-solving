#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

const int LM = 1005;
const int INF = 1e9 + 10;

vector<pii> adj[LM];

int v, e, st, en;
int d[LM];
int pre[LM];


int main() {
	scanf("%d%d", &v, &e);
	fill(d, d + v + 1, INF);

	while (e--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({ w,v });
	}

	scanf("%d%d", &st, &en);
	
	// Dijkstra
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[st] = 0;

	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (d[cur.Y] != cur.X) continue;
		for (auto next : adj[cur.Y]) {
			if (d[next.Y] <= d[cur.Y] + next.X) continue;

			d[next.Y] = d[cur.Y] + next.X;
			pq.push({ d[next.Y], next.Y });
			pre[next.Y] = cur.Y;
		}
	}

	printf("%d\n", d[en]);
	vector<int> path;
	int cur = en;

	while (cur != st) {
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);
	reverse(path.begin(), path.end());
	printf("%d\n", path.size());
	for (auto x : path) printf("%d ", x);
}

