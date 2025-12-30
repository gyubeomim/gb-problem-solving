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
int dist[LM][LM], path[LM][LM];

void floyd(){
	int i,j,k;
	for(k=1;k<=N;k++){
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}

void trace(int s, int e){
	if(path[s][e] == 0){
		printf("%d ", s); return;
	}
	trace(s, path[s][e]);
	trace(path[s][e], e);
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d1992.txt", "r", stdin);
#endif
		scanf("%d%d",&N,&M);
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				scanf("%d", dist[i]+j);
			}
		}
		floyd();
		printf("%d\n", dist[1][M]);
		trace(1,M);
		printf("%d\n", M);
}