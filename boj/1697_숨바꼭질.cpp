#include <bits/stdc++.h>
using namespace std;

const int LM = 100005;
int dist[LM];
int N,K;

int main(int argc, char **argv){
	scanf("%d%d",&N,&K);
	fill(dist, dist+LM, -1);

	dist[N] = 0;
	queue<int> Q; Q.push(N);

	while(dist[K] == -1) {
		int cur = Q.front(); Q.pop();
		for(int nxt : {cur-1, cur+1, cur*2}) {
			if(nxt<0 || nxt>LM) continue;
			if(dist[nxt]!=-1) continue;
			dist[nxt] = dist[cur]+1;
			Q.push(nxt);
		}
	}
	printf("%d", dist[K]);
}
