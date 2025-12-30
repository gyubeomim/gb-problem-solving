#include <bits/stdc++.h>
using namespace std;
vector<int> graph[11];
int N, ans=0x3f3f3f3f;
int comb[11], popluation[11], parent[11];

int FindParent(int x) {
	if(x == parent[x]) return x;

	parent[x] = FindParent(parent[x]);
	return parent[x];
}

void Merge(int a, int b) {
	a = FindParent(a);
	b = FindParent(b);

	if(a < b) parent[b] = a;
	else parent[a] = b;
}

bool BFS(vector<int> area) {
	int ck[11] = {0};

	queue<int> Q;
	Q.push(area[0]);
	ck[area[0]] = 1;

	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();

		for(auto next : graph[x]) {
			if(ck[next] || parent[next] != parent[x]) continue;
			Q.push(next);
			ck[next] = 1;
		}
	}

	for(auto a : area) {
		if(!ck[a]) return false;
	}

	return true;
}

void DFS(int depth, int idx, int range) {
	if(depth == range){
		vector<int> area1, area2;
		int sum1=0, sum2=0;

		for(int i=1; i<=N; i++){
			parent[i] = i;
		}
		
		for(int i=1; i<=N; i++) {
			if(comb[i]) {
				area1.push_back(i);
				sum1 += popluation[i];
			}
			else {
				area2.push_back(i);
				sum2 += popluation[i];
			}
		}

		for(int i=0; i<area1.size()-1; i++) Merge(area1[i], area1[i+1]);
		for(int i=0; i<area2.size()-1; i++) Merge(area2[i], area2[i+1]);

		if(BFS(area1) && BFS(area2)) 
			ans = min(ans, abs(sum1-sum2));

		return;
	}

	for(int i=idx; i<=N; i++){
		if(comb[i]) continue;

		comb[i] = 1;
		DFS(depth+1, i+1, range);
		comb[i] = 0;
	}
}


int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> popluation[i];
	}

	for(int i=1; i<=N; i++){
		int e;
		cin >> e;
		for(int j=0; j<e; j++){
			int v;
			cin >> v;

			graph[i].push_back(v);
			graph[v].push_back(i);
		}
	}

	for(int i=1; i<=N/2; i++){
		memset(comb, 0, sizeof(comb));
		DFS(0,1,i);
	}

	if(ans == 0x3f3f3f3f) cout << "-1";
	else cout << ans;
	 

	return 0;
}
