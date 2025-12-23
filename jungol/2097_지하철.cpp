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

const int LM = 105;
const int INF = 0x3f3f3f3f;

int N,M;
int A[LM][LM];
int dist[LM], path[LM], visited[LM];

int dijkstra() {
  for (int i = 1; i <= N; i++) dist[i] = INF;
  dist[1] = 0;

  for (int i = 1; i <= N; i++) {
    int min_node = 0, min_dist = INF;
    for (int j = 1; j <= N; j++) {
      if (visited[j] == 0 && dist[j] < min_dist) {
        min_node = j;
        min_dist = dist[j];
      }
    }

    visited[min_node] = 1;
    if (min_node == M) return dist[min_node];

    for (int j = 1; j <= N; j++) {
      if (dist[j] > min_dist + A[min_node][j]) {
        dist[j] = min_dist + A[min_node][j];
        path[j] = min_node;
      }
    }
  }
  return -1;
}

void trace(int u){
	if(u==0) return;
	trace(path[u]);
	printf("%d ", u);
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d1992.txt", "r", stdin);
#endif
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", A[i] + j);
		}
	}
	printf("%d\n", dijkstra());
	trace(M);
}