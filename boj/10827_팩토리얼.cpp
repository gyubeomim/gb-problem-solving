#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main(int argc, char **argv){
	int N;
	scanf("%d", &N);
	
	ll ans=1;
	for(int i=1; i<=N; i++){
		ans *= i;
	}

	printf("%lld", ans);
}
