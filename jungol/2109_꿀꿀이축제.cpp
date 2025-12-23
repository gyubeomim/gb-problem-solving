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

const int LM = 1005;
const int INF = 0x3f3f3f3f;

int N,M,X_;
vector<pii> fadj[LM], badj[LM];
int fdist[LM], bdist[LM];
int visited[LM], vcnt;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(vector<pii> adj[], int dist[]){
	for(int i=1;i<=N;i++) dist[i]=INF;
	dist[X_]=0;
	pq={};
	++vcnt;

	pq.push({0, X_});
	while(!pq.empty()){
		int min_dist = pq.top().X;
		int min_node = pq.top().Y;
		pq.pop();

		if(visited[min_node] == vcnt) continue;
		visited[min_node] = vcnt;

		for(auto& a : adj[min_node]){
			if(dist[a.Y] > min_dist + a.X){
				dist[a.Y] = min_dist + a.X;
				pq.push({dist[a.Y], a.Y});
			}
		}
	}
}


int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d1932.txt", "r", stdin);
#endif
	scanf("%d%d%d",&N,&M,&X_);

	for(int i=0; i<M; i++){
		int s,e,w;
		scanf("%d%d%d",&s,&e,&w);
		fadj[s].push_back({w,e});
		badj[e].push_back({w,s});
	}

	dijkstra(badj, bdist);
	dijkstra(fadj, fdist);

	int ans=0;
	for(int i=1;i<=N;i++){
		ans = max(ans, fdist[i] + bdist[i]);
	}
	printf("%d\n", ans);
}