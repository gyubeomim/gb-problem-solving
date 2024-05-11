#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM = 20005;
constexpr int BLUE = 2;
constexpr int RED = 3;

int K,V,E;
vector<int> graph[LM];
int visited[LM];

void DFS(int cur, int color) {
	if(visited[cur]==1) visited[cur] = color;

	for(int next : graph[cur]){
		if(visited[next] > 1) continue;
		DFS(next, visited[cur]==BLUE ? RED : BLUE);
	}
}

bool checkBipartedGraph() {
	for(int i=0; i<LM; i++) {
		for(int j=0; j<graph[i].size(); j++){
			int next = graph[i][j];
			if(visited[i] == visited[next]) {
				return false;
			}
		}
	}
	return true;
}


int main(int argc, char **argv){
	scanf("%d", &K);

	while(K--) {
		for(int i=0; i<LM; i++){
			graph[i].clear();
			visited[i] = 1;
		}

		scanf("%d %d", &V, &E);
		for(int i=0; i<E; i++){
			int a,b;
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for(int i=0; i<V; i++){
			if(visited[i] == 1 && graph[i].size()) 
				DFS(i, BLUE);
		}

		if(checkBipartedGraph()) printf("YES\n");
		else printf("NO\n");
	}
}
