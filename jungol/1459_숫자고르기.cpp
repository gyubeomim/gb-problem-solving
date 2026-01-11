#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 105;

int N;
int A[LM];
int visited[LM], finished[LM];

vector<int> V;

void dfs(int c){
	if(visited[c]) return;

	visited[c] = 1;
	int &nc = A[c];

	dfs(nc);

	if(!finished[nc]){
		for(int i=nc;; i=A[i]){
			V.push_back(i);
			if(i == c) break;
		}
	}
	finished[c] = 1;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1459.txt", "r", stdin);
	#endif

	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &A[i]);
	}

	for(int i=1; i<=N; i++){
		if(!visited[i]) dfs(i);
	}

	sort(V.begin(), V.end());
	
	printf("%d\n", (int)V.size());
	for(auto v : V){
		printf("%d\n", v);
	}
}