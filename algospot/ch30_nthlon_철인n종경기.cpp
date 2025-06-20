#include <bits/stdc++.h>
#define X first
#define Y second
using pii = std::pair<int,int>;
using namespace std;

const int INF = 987654321;
const int LM = 410;
const int START = 401;

int V;
vector<pii> adj[LM];

vector<int> dijkstra(int src){
	vector<int> dist(V, INF);
	dist[src] = 0;

	priority_queue<pii> pq;
	pq.push({0, src});

	while(!pq.empty()){
		int cost = -pq.top().X;
		int here = pq.top().Y;
		pq.pop();

		// 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시
		if(dist[here] < cost) continue;

		// 인접한 정점들을 모두 검사한다
		for(int i=0;i<adj[here].size();i++){
			int there = adj[here][i].X;
			int nextDist = cost + adj[here][i].Y;
			// 더 짧은 경로를 발견하면 dist[]를 갱신하고 우선순위큐에 넣는다
			if(dist[there] > nextDist){
				dist[there] = nextDist;
				pq.push({ -nextDist, there });
			}
		}
	}
	return dist;
}


int solve(const vector<int>&a, const vector<int>&b){
	// 그래프를 만든다
	V = 402;

	for(int i=0;i<V;i++) adj[i].clear();
	
	for(int i=0;i<a.size();i++){
		int delta = a[i] - b[i];
		adj[START].push_back({ delta+200, a[i] });
	}	

	// 현재 차이
	for(int delta=-200; delta<=200; delta++){
		// i번 종목을 뒤에 붙인다면?
		for(int i=0; i<a.size(); i++){ 
			int next = delta + a[i] - b[i];
			// 시간 차이의 절대값이 200을 넘는 정점은 만들 필요가 없다
			if(abs(next)>200) continue;
			adj[delta+200].push_back({ next+200, a[i] });
		}
	}

	vector<int> shortest = dijkstra(START);

	int ret = shortest[0 + 200];
	if(ret == INF) return -1;
	return ret;
}

vector<int> a,b;
int ans;
int M;

int main(int argc, char **argv){
  //freopen("s_in_2233.txt", "r", stdin); 
  int C; scanf("%d",&C);
  while(C--){
	a.clear(); b.clear();
	scanf("%d", &M);

	a.assign(M, 0);
	b.assign(M,0);

	for(int i=0;i<M;i++){
		scanf("%d%d", &a[i], &b[i]);
	}
	
	ans = solve(a,b);

	if(ans != -1) printf("%d\n", ans);
	else printf("IMPOSSIBLE\n");
  }
}
