#include <bits/stdc++.h>
#define rnt register int
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM = 2005;
int N,M;
vector<int> adj[LM];
int visited[LM];
bool found=false;

void DFS(int c, int depth){
	if(depth==4) {
		found=true;
		return;
	}

	for(auto next : adj[c]) {
		if(!visited[next]) {
			visited[c] = true;
			DFS(next, depth+1);
			visited[c] = false;
		}
	}
}

int main(int argc, char **argv){
	scanf("%d %d",&N,&M);

	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i=0; i<N; i++) {
		memset(visited,0,sizeof(visited));
		DFS(i, 0);
		if(found) break;
	}

	printf("%d", found);
}
