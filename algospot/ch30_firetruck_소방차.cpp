#include <bits/stdc++.h>
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 1005;

int V,E,N,M;
vector<vector<pii>> adj;

int station[LM], burn[LM];
bool is_station[LM];
int dist[LM];

void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push( {0, start});
	dist[start] = 0;

	int now_place, cost, next_place, next_cost;
	while(!pq.empty()){
		now_place = pq.top().second;
		cost = pq.top().first;
		pq.pop();

		if(dist[now_place] < cost) continue;

		for(int i=0; i<adj[now_place].size(); i++){
			next_place = adj[now_place][i].second;
			
			// 다음 장소가 소방소라면 더이상 탐사하지 않음
			if(is_station[next_place]) continue;

			next_cost = cost + adj[now_place][i].first;

			if(next_cost < dist[next_place]){
				pq.push( {next_cost, next_place} );
				dist[next_place] = next_cost;
			}
		}
	}
}

int main(int argc, char **argv){
//freopen("s_in_2211.txt", "r", stdin);
  int C; scanf("%d",&C);
  while(C--){
	scanf("%d%d%d%d",&V,&E,&N,&M);

	memset(is_station, 0 , sizeof(is_station));
	memset(dist, 0x7f, sizeof(dist));

	adj = vector<vector<pii>>(V+1);

	for(int i=0;i<E;i++){
		int a,b,cost;
		scanf("%d%d%d",&a,&b,&cost);
		adj[a].push_back( {cost, b});
		adj[b].push_back( {cost, a});
	}

	for(int i=0; i<N; i++){
		scanf("%d", &burn[i]);
	}

	for(int i=0; i<M; i++){
		scanf("%d", &station[i]);
		is_station[station[i]] = 1;
	}

	for(int i=0; i<M; i++){
		dijkstra(station[i]);
	}

	ll total_cost = 0;
	for(int i=0; i<N; i++){
		total_cost += dist[burn[i]];
	}
	
	printf("%lld\n", total_cost);
  }
}
