#include <bits/stdc++.h>
using namespace std;

const int LM = 50;
const int EMPTY = -0x3f3f3f3f;

int N, board[LM];
int cache[LM][LM];

int play(int left, int right){
	// 기저 사례 : 모든 수가 다 없어졌을 때
	if(left > right) return 0;

	int& ret = cache[left][right];
	if(ret!=EMPTY) return ret;

	// 수를 가져가는 경우
	ret = max(board[left] - play(left+1, right),
						board[right] - play(left, right-1));

	// 수를 없애는 경우
	if(right - left + 1 >= 2){
		ret = max(ret, -play(left+2, right));
		ret = max(ret, -play(left, right-2));
	}
	return ret;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		// freopen("data/d1291.txt", "r", stdin);
	#endif
		int C; scanf("%d",&C);
		while(C--) {
			scanf("%d", &N);

			for(int i=0; i<LM;i++){
				for(int j=0; j<LM;j++){
					cache[i][j] = EMPTY;				
				}
			}
			memset(board, 0, sizeof(board));

			for(int i=0; i<N; i++) 
				scanf("%d", &board[i]);

			int ans = play(0, N-1);
			printf("%d\n", ans);
		}
}