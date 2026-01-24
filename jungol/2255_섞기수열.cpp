#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 20005;
int P[LM], A[LM], visited[LM];
int N;

ll GCD(ll a, ll b){
	while(b) { ll t = a%b; a=b; b=t; }
	return a;
}

ll LCM(ll a, ll b){
	return a / GCD(a,b) * b;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d2255.txt", "r", stdin);
	#endif

	scanf("%d", &N);
	for(int i=1;i<=N;i++){
		scanf("%d", &P[i]);
	}
	
	for(int k=1; k<=N; k++){
		A[P[k]] = k;
	}

	ll ans = 1;

	for(int i=1; i<=N; i++){
		if(visited[i]) continue;
		int cur = i;
		int cnt = 0;
		while(!visited[cur]){
			visited[cur] = 1;
			cur = A[cur];
			cnt++;
		}
		ans = LCM(ans, cnt);
	}
	printf("%lld\n", ans);
}