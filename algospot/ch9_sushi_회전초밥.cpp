#include <bits/stdc++.h>
using namespace std;

const int LM = 205;
int N, M, price[20], pref[20];
int c[LM];

// 최대 만족도의 합을 반환한다
// M과 price[]는 이미 100으로 나뉘어 있다고 가정한다
int sushi3() {
	int ret = 0;
	c[0] = 0;
	for(int budget=1; budget<=M; budget++){
		int cand = 0;
		for(int dish=0; dish<N; dish++){
			if(budget >= price[dish]) 
				cand = max(cand, c[(budget - price[dish])%LM] + pref[dish]);
		}
		c[budget % LM] = cand;
		ret = max(ret, cand);
	}
	return ret;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		// freopen("data/d1931.txt", "r", stdin);
	#endif
		int C; scanf("%d",&C);
		while(C--) {
			scanf("%d%d", &N, &M);
			M /= 100;
			for(int i=0; i<N; i++){
				scanf("%d%d", &price[i], &pref[i]);
				price[i] /= 100;
			}

			int ans = sushi3();
			printf("%d\n", ans);
		}
}