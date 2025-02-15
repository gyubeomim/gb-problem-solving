#include <bits/stdc++.h>

const int LM=1005;
const int MOD=10007;

int comb[LM][LM];

int main(int argc, char **argv){
	for(int i=1;i<=1000;i++){
		comb[i][0] = comb[i][i] = 1;
		for(int j=1; j<i; j++){
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%MOD;
		}
	}

	int N,M;
	scanf("%d%d",&N,&M);
	printf("%d\n", comb[N][M]);
}
