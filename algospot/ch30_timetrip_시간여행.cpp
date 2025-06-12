#include <bits/stdc++.h>
#define X first
#define Y second
using pii = std::pair<int,int>;
using namespace std;

const int INF = 987654321;
const int LM = 100;

int V, E;
vector<pii> adjmax[LM];
vector<pii> adjmin[LM];

bool reachable[LM][LM];

// floyd 알고리즘을 이용해 reachable 계산
void calcReachable(){
	for(int i=0; i<V; i++) 
		reachable[i][i] = true;

	for(int k=0; k<V; k++) {
		for(int i=0; i<V; i++){
				for(int j=0; j<V; j++){
					reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
				}
		}
	}
}

int bellman2(int src, int target, vector<pii>* adj){
	vector<int> upper(V,INF);
	upper[src] = 0;

  // V-1번 순회한다
	for(int k=0; k<V-1; k++){
		for(int cur=0; cur<V; cur++) {
			for(int i=0; i<adj[cur].size(); i++){
				int next = adj[cur][i].X;
				int cost = adj[cur][i].Y;
				upper[next] = min(upper[next], upper[cur]+cost);
			}
		}
	}

	// 음수 사이클의 존재 여부를 확인하자
	for(int cur=0; cur<V; cur++){
		for(int i=0; i<adj[cur].size(); i++){
			int next = adj[cur][i].X;
			int cost = adj[cur][i].Y;
			// 완화가 성공한다면 cur은 음수 사이클이 들어있다는 의미
			if(upper[cur]+cost < upper[next]){
				// 이 음수 사이클을 포함하는 경로가 있는가?
				if(reachable[src][cur] && reachable[cur][target])
					return -INF;
			}
		}
	}
	return upper[target];
}

int main(int argc, char **argv){
	freopen("s_in_1125.txt", "r", stdin);

	int C; scanf("%d", &C);
	while(C--) {
		memset(reachable, false, sizeof(reachable));
		for(int i=0; i<LM; i++){
			adjmax[i].clear();
			adjmin[i].clear();
		}

		scanf("%d%d", &V, &E);
		for(int i=0; i<E; i++){
			int src, des, cost;
			scanf("%d%d%d", &src, &des, &cost);
			adjmin[src].push_back( {des, cost} );
			adjmax[src].push_back( {des, -cost} );
			reachable[src][des] = true;
		}

		calcReachable();
		int min_ = bellman2(0, 1, adjmin);
		int max_ = bellman2(0, 1, adjmax);

		printf("min %d, max %d\n", min_, max_);

		if(!reachable[0][1]) printf("UNREACHABLE\n");
		else {
			if(min_ == -INF) printf("INFINITY ");
			else printf("%d ", min_);

			if(max_ == -INF) printf("INFINITY\n");
			else printf("%d\n", -max_);
		}
	}
}