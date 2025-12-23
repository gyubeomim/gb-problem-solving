#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

constexpr int LM = 1005;
int N,M;
vector<int> adj[LM];
int visited[LM];

int que[LM*LM];
int fr,re;

bool dfs(int node) {
	if(visited[node]) return false;
	visited[node] = 1;

	for(int next : adj[node]){
		if(visited[next]) continue;
		dfs(next);
	}
	return true;
}

bool bfs(int node){
	if(visited[node]) return false;

	que[re++] = node;
	visited[node] = 1;

	while(fr < re) {
		int cur = que[fr++];

		for(int next : adj[cur]){
			if(visited[next]) continue;
			que[re++] = next;
			visited[next] = 1;
		}
	}
	return true;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d2222.txt", "r", stdin);
	#endif

	scanf("%d%d", &N, &M);
	for(int i=0; i<M; i++){
		int a,b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans = 0;
	for(int i=1; i<=N; i++){
		// if(bfs(i)){
		if(dfs(i)){
			ans++;
		}
	}
	printf("%d\n", ans);
}