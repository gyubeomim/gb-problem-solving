#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM = 1005;
int N,M;
vector<int> graph[LM];
int check[LM];
int visited[LM];
int answer=0;

void DFS(int cur) {
	visited[cur]=true;

	for(int v : graph[cur]) {
		if(visited[v]) continue;
		DFS(v);
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	scanf("%d %d",&N,&M);

	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i=1; i<=N; i++){
		if(!visited[i]) {
			answer++;
			DFS(i);
		}
	}

	printf("%d", answer);

}
