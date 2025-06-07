#include <bits/stdc++.h>
#define X first
#define Y second
using pid = std::pair<int, double>;
using pdi = std::pair<double, int>;
using namespace std;

const int LM = 10005;
const double INF = numeric_limits<double>::max();
int V, edges;

vector<pid> adj[LM];
vector<double> ans;

void dijkstra( int src ) {
	ans = vector<double>(V, INF);

	// 간선을 지날 때마다 곱 연산을 해야하므로 초기값 1.0
  ans[src] = 1.0;   

	// {해당 정점까지 증폭량, 정점 번호}
  priority_queue<pdi> pq;

	// 우선순위 큐는 디폴트가 내림차순이므로 -1 곱해서 넣어준다
  pq.push( make_pair( -1.0, src ) );   

  while ( !pq.empty() ) {
    double cost = -pq.top().X;
    int here = pq.top().Y;
    pq.pop();

    if ( ans[here] < cost ) continue;
	
    for ( int i = 0; i < adj[here].size(); i++ ) {
      int there = adj[here][i].X;
      double nextDist = cost * adj[here][i].Y;

      if ( ans[there] > nextDist ) {
        ans[there] = nextDist;
        pq.push( make_pair( -nextDist, there ) );
      }
    }
  }
}

int main( int argc, char **argv ) {
	//freopen("d_1123.txt", "r", stdin);
	int C; scanf("%d",&C);
	while(C--) {
		scanf("%d%d",&V,&edges);

		for(int i=0;i<V;i++){
			adj[i].clear();
		}
		
		int a,b; 
		double c;
		for(int i=0; i<edges; i++){
			scanf("%d%d%lf", &a, &b, &c);
			adj[a].push_back(make_pair(b,c));
			adj[b].push_back(make_pair(a,c));
		}

		dijkstra(0);
		printf("%lf\n", ans[V-1]);
	}
}
