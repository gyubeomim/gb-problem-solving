#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM = 15;

int N;
int D[LM] = {0};

int main(int argc, char **argv){
	int T; scanf("%d", &T);

	while(T--) {
		memset(D,0,sizeof(D));
		D[1]=1;
		D[2]=2;
		D[3]=4;
		for(int i=4; i<LM; i++){
			D[i] = D[i-1]+D[i-2]+D[i-3];
		}

		scanf("%d", &N);
		printf("%d\n", D[N]);
	}
}
