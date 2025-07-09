//user.cpp
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
using pii = pair<int, int>;

const int LM = 305;
const int ELM = 3500;
const int INF = 0x3f3f3f3f;

int N;
unordered_map<int, pii> hmap; // {eid, {nid1, nid2}}
vector<pii> adj[LM];          // adj[nid1] = {cost, nid2}
struct Data{
	int city, cost, discount;
	bool operator<(const Data& t) const {
		return cost > t.cost; // pq 부등호 방향은 set과 반대이다
	}
};
priority_queue<Data> pq;
int dist[LM][11], visited[LM][11];

void add(int mId, int sCity, int eCity, int mToll) {
	hmap[mId] = {sCity, eCity};
	adj[sCity].push_back({mToll, eCity});
}

void init(int N, int K, int mId[], int sCity[], int eCity[], int mToll[]) {
	hmap.clear();
	::N = N;
	for(int i=0; i<=N; i++) adj[i].clear();
	for(int i=0; i<K; i++) add(mId[i], sCity[i], eCity[i], mToll[i]);
}

void remove(int mId) {
	int u = hmap[mId].X, v = hmap[mId].Y;
	hmap.erase(mId);
	int len = (int)adj[u].size();
	for(int i=0; i<len; i++){
		if(adj[u][i].Y == v) {
			adj[u][i] = adj[u].back();
			adj[u].pop_back();
			break;
		}
	}
}

int cost(int M, int sCity, int eCity) {
	for(int i=0; i<=N; i++){
		for(int j=0; j<=M; j++){
			dist[i][j] = INF;
			visited[i][j] = 0;
		}
	}
	pq={};
	dist[sCity][0] = 0;
	pq.push({sCity, 0, 0});

	while(!pq.empty()){
		// extract min_node, min_dist
		Data t = pq.top(); pq.pop();
		if(t.city == eCity) return t.cost;
		// check min_node
		if(visited[t.city][t.discount]) continue;
		visited[t.city][t.discount] = 1;
		// relaxation
		for(auto& a : adj[t.city]) {
			int nextCost = a.X, nextCity = a.Y;
			// 쿠폰을 사용하지 않는 경우
			if(dist[nextCity][t.discount] > t.cost + nextCost){
				dist[nextCity][t.discount] = t.cost + nextCost;
				pq.push({nextCity, dist[nextCity][t.discount], t.discount});
			}
			// 쿠폰을 사용하는 경우
			if(t.discount < M && dist[nextCity][t.discount+1] > t.cost + nextCost/2){
				dist[nextCity][t.discount+1] = t.cost + nextCost/2;
				pq.push({nextCity, dist[nextCity][t.discount+1], t.discount+1});
			}
		}
	}
	return -1;
}