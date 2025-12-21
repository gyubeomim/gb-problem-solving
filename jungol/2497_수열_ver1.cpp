#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

constexpr int LM = 100005;
int N, K;
int arr[LM];
int pre[LM];

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d4920.txt", "r", stdin);
	#endif

	scanf("%d%d",&N,&K);

	int ans = -1e9;
	int sum = 0;

	// prefix sum
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
		pre[i] = pre[i-1] + arr[i];
		// printf("pre[i] %d\n", pre[i]);
	}

	for(int e=K; e<=N; e++){
		int s = e - K + 1;
		int sum = pre[e] - pre[s-1];
		ans = max(ans, sum);
	}

	printf("%d\n", ans);
}