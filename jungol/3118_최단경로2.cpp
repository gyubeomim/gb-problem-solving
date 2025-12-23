#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 100005;
const int INF = 0x3f3f3f3f;

int N,M;
vector<pii> adj[LM];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dist[LM], visited[LM];

int dijkstra(){
	for(int i=1; i<=N; i++) dist[i] = INF;
	dist[1] = 0;
	pq.push({0,1});

	while(!pq.empty()){
		int min_dist = pq.top().X;
		int min_node = pq.top().Y;
		pq.pop();

		if(visited[min_node]) continue;
		if(min_node == N) return min_dist;

		visited[min_node] = 1;

		for(auto& a: adj[min_node]){
			if(dist[a.Y] > min_dist + a.X){
				dist[a.Y] = min_dist + a.X;
				pq.push({ min_dist + a.X, a.Y });
			}
		}
	}
	return INF;
}



int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d1883.txt", "r", stdin);
#endif
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		adj[a].push_back({c,b});
	}
	printf("%d\n", dijkstra());
}
