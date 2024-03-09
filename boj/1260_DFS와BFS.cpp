#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int LM = 1005;

int N,M,V;
vector<int> graph[LM];
int visited[LM];

void DFS(int s) {
	if(visited[s]) return;

	visited[s] = 1;
	
	printf("%d ", s);


	for(auto g : graph[s]) {
		if(!visited[g]) DFS(g);
	}
	
}

int que[LM*LM];
int fr,re;

void BFS(int s) {
	fr = re = 0;
	memset(visited, 0, sizeof(visited));
	
	que[re++] = { s };
	visited[s] = 1;

	while(fr < re) {
		int val = que[fr++];

		printf("%d ", val);

		for(auto g : graph[val]) {
			if(visited[g]) continue;

			visited[g] = 1;
			que[re++] = { g };
		}
	}

}

int main(int argc, char **argv){
	scanf("%d %d %d",&N, &M, &V);

	for(int i=0; i<M; i++){
		int a,b;
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	// sort
	for(int i=0; i<LM; i++){
		if(!graph[i].empty()) {
			sort(graph[i].begin(), graph[i].end());
		}
	}


	DFS(V);
	puts("");
	BFS(V);
	puts("");

	return 0;
}
