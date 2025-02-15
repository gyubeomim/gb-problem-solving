#include <bits/stdc++.h>
using namespace std;

const int LM = 32005;

vector<int> adj[LM];
int deg[LM];
int N, M;

int main() {
	scanf("%d%d", &N, &M);

	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		deg[b]++;
	}

	queue<int> q;
	vector<int> result;

	for (int i = 1; i <= N; i++)
		if (deg[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		result.push_back(cur);

		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	for (auto x : result) printf("%d ", x);
}

