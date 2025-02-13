#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int,int,int>;

vector<int> parent(10005,-1);

int find(int x){
	if(parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

bool Union(int a, int b){
	a = find(a); b = find(b);
	if(a == b) return 0;

	if(parent[a] == parent[b]) parent[a]--;
	if(parent[a] < parent[b]) parent[b] = a;
	else parent[a] = b;

	return 1;
}

int v, e;
tiii edge[100005];

int main(void) {
	scanf("%d%d", &v, &e);
	for(int i = 0; i < e; i++){
		int a, b, cost;
		scanf("%d%d%d",&a,&b,&cost);
		edge[i] = {cost, a, b};
	}

	sort(edge, edge + e);

	int cnt = 0;
	int ans = 0;

	// Kruskal algorithm (using Union-find)
	for(int i = 0; i < e; i++){
		int a, b, cost;
		tie(cost, a, b) = edge[i];

		if(!Union(a, b)) continue;

		ans += cost;
		cnt++;
		if(cnt == v-1) break;
	}

	printf("%d\n", ans);
}

