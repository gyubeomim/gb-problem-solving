#include <bits/stdc++.h>
#define X first
#define Y second
using pii = std::pair<int,int>;
using namespace std;

const int INF = numeric_limits<int>::max();
const int LM = 1005;

int V;
vector<pii> adj[LM]; // adj[here] = {node, weight}

// 음수 사이클이 있을 경우 텅 빈 배열을 반환
vector<int> bellmanFord(int src){
	// 시작점을 제외한 모든 정점까지의 최단거리 상한을 INF로 둔다
  vector<int> upper( V, INF );
	upper[src] = 0;
	bool updated;

	// V번 순회한다 (V-1번까지 최단거리 찾고 마지막 V번째에 음수 사이클 확안)
	for(int k=0; k<V; k++){
		updated = false;
		for(int cur; cur<V; cur++){
			for(int i=0; i<adj[cur].size(); i++){
				int next = adj[cur][i].X;
				int cost = adj[cur][i].Y;
				// (cur, next) 간선을 따라 완화를 시도한다
				if(upper[next] > upper[cur] + cost){
					upper[next] = upper[cur] + cost;
					updated = true;
				}
			}
		}
		if(!updated) break;
	}

	if(updated) upper.clear();
	return upper;
}

int main(int argc, char **argv){

}