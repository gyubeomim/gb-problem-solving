#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int N, M;
int dice[10];

void dfs(int d){
	if(d == N){
		int sum = 0;
		for(int i=0; i<N; i++){
			sum += dice[i];
		}
		if(sum == M) {
			for(int i=0; i<N; i++){
				printf("%d ", dice[i]);
			}puts("");
		}
		return;
	}

	for(int i=1; i<=6; i++){
		dice[d] = i;
		dfs(d+1);
	}
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1175.txt", "r", stdin);
	#endif

	scanf("%d%d", &N, &M);

	dfs(0);
}