#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using ll = long long;
using tlii = std::tuple<ll, int, int>;
using pii = std::pair<int, int>;
using namespace std;

constexpr int NLM = 10005;
constexpr int KLM = 21;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

int N,M,K;
vector<pii> adj[NLM];
ll dist[NLM][KLM];

void dijkstra(){
	for(int i=1;i<=N;i++){
		for(int j=0;j<=K;j++){
			dist[i][j] = INF;
		}
	}
	
	priority_queue<tlii, vector<tlii>, greater<tlii>> pq;

	dist[1][0] = 0;
	pq.push({0, 1, 0}); // { dist, node, useK }

	while(!pq.empty()){
		auto [d, v, k] = pq.top(); pq.pop();

		if(dist[v][k] < d) continue;

		for(auto &[nv, nw] : adj[v]){
			ll nd = d + nw;

			if(dist[nv][k] > nd) {
				dist[nv][k] = nd;
				pq.push({dist[nv][k], nv, k});
			}

			if(k < K && dist[nv][k+1] > d){
				dist[nv][k+1] = d;
				pq.push({dist[nv][k+1], nv, k+1});
			}
		}
	}
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d8339.txt", "r", stdin);
	#endif	

	scanf("%d%d%d", &N,&M,&K);
	for(int i=0; i<M; i++){
		int u,v,w; scanf("%d%d%d", &u,&v,&w);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dijkstra();

	ll ans = INF;
	for(int k=0; k<=K; k++){
		ans = min(ans, dist[N][k]);
	}
	printf("%lld\n", ans);
}