#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM=1'000'005;
bool is_prime[LM];

int main(int argc, char **argv){
	int N,M;
	scanf("%d %d", &N,&M);
	
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0]=false;
	is_prime[1]=false;
	for(int i=2; i*i<LM; i++) {
		if(is_prime[i]==false) continue;
		for(int j=i*i; j<LM;j+=i){
			is_prime[j]=false;
		}
	}

	for(int i=N; i<=M; i++){
		if(is_prime[i])
			printf("%d\n", i);
	}

}
