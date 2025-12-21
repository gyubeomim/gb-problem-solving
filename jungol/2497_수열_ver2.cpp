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

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d4920.txt", "r", stdin);
	#endif

	scanf("%d%d",&N,&K);

	int ans = -1e9;
	int sum = 0;
	for(int i=0; i<N; i++){
		int n; scanf("%d", &n);
		arr[i] = n;

		sum += arr[i];
		// printf("sum %d\n", sum);
		if(i >= K-1){
			sum -= arr[i-K];
			ans = max(ans, sum);
		}
	}

	printf("%d\n", ans);
}