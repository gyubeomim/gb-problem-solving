#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
bool visited[100001]={0};
int result[100001];
int cnt=0;

void dfs(int now){
	if(visited[now]){
		return ;
	}

	visited[now]=true;
	cnt++;
	result[now]=cnt;

	for(int i=0; i<graph[now].size();i++){
		dfs(graph[now][i]);
	}

}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N,M,R;
	cin>>N>>M>>R;

	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
graph[u].push_back(v);
graph[v].push_back(u);
	}

	for(int i=1;i<=N;i++){
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(R);

	for(int i=1;i<=N;i++){
		cout << result[i] << '\n';
	}
	 

	return 0;
}
