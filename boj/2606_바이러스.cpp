#include <bits/stdc++.h>

using namespace std;



vector<vector<int>> g;
vector<int> visit;


int ans=0;

void dfs(int now) {
  visit[now] = 1;

  for (int i = 0; i < g[now].size(); i++) {
    if (!visit[g[now][i]]) {
      dfs(g[now][i]);
      ans++;
    }
  }
}





int main() {
	int N;
	cin >> N;

	g.resize(N+1);
	visit.resize(N+1);

	int M; 
	cin >> M;

	for(int i=0;i<M;i++) {
		int a,b;
		cin >> a >> b;


		g[a].push_back(b);
		g[b].push_back(a);
	}


	dfs(1);


	cout << ans << '\n';
}