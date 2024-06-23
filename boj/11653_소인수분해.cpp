#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM=10'000'000;
int N;
bool isprime[LM];

int main(int argc, char **argv){
	scanf("%d",&N);
		
	isprime[0] = false;
	isprime[1] = false;

	for(int i=2; i*i<LM; i++) {
		if(!isprime[i]) continue;
		isprime[i] = false;
		for(int j=i*i; j<LM; j+=i) {
			isprime[j] = false;
		}
	}
	
	int div=2;
	while(N > 1) {
		if(N % div == 0) {
			N /= div;
			printf("%d\n", div);
		} 
		else{
			div++;
		}

		if(div > N) {
			if(isprime[N]) {
				printf("%d", N);
				break;
			}
		}
	}


}
