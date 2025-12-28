#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 10005;

unordered_map<int, vector<int>> hmap;

int N,M,K;
vector<pii> adj[LM];

pii que[50005];
int visited[LM];
int fr,re;

void bfs(){
	fr=re=0;

	que[re++] = {1, 0};  // { node, weight }
	visited[1] = 1;

	while(fr<re){
		pii cur = que[fr++];
		int &u = cur.X;
		int &w = cur.Y;

		if(u == N){
			break;
		}	

		for(auto next : adj[u]){
			int &nv = next.X;
			int &nw = next.Y;
			if(visited[nv]) continue;

			que[re++] = {nv, nw};
			visited[nv] = 1;
		}
	}

	sort(hmap[N].begin(), hmap[N].end(), greater<int>());
	while(K--){
		hmap.erase(hmap.begin());
	}



}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d8339.txt", "r", stdin);
#endif
	scanf("%d%d%d", &N,&M,&K);
	for(int i=0; i<M; i++){
		int u,v,w; scanf("%d%d%d", &u,&v,&w);
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	bfs();
}