#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM = 15;
constexpr int MOD = 1'000'000'009;

int N;
ll D[LM][4];


int main(int argc, char **argv){
	int T; scanf("%d", &T);

	while(T--) {
		memset(D,0,sizeof(D));
		
		// D[n][i] = 마지막에 오는 수가 i일 때, 1,2,3의 합으로 정수 n을 만드는 경우의 수
		D[1][1] = D[2][2] = 1;
		D[3][1] = D[3][2] = D[3][3] = 1;

		for(int i=4; i<=LM; i++){
			D[i][1] = (D[i-1][2] + D[i-1][3]) % MOD;
			D[i][2] = (D[i-2][1] + D[i-2][3]) % MOD;
			D[i][3] = (D[i-3][1] + D[i-3][2]) % MOD;
		}
		
		scanf("%d", &N);
		printf("%lld, %lld, %lld\n", D[N][1], D[N][2], D[N][3]);
		printf("%lld\n", D[N][1] + D[N][2] + D[N][3]);
	}
}
