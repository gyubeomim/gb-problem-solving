#include <bits/stdc++.h>
using namespace std;

const int LM = 100005;

int n;
vector<int> adj[LM];
int parent[LM];

void dfs(int c) {
	for (int nxt : adj[c]) {
		if (parent[c] == nxt) continue;
		parent[nxt] = c;
		dfs(nxt);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) printf("%d\n", parent[i]);
}

