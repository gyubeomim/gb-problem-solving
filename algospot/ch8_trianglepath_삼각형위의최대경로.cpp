#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 100;

int N;
int triangle[LM][LM];
int dp[LM][LM];

// (y,x) 위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반환한다
int path2(int y, int x){
	if(y == N-1) return triangle[y][x];

	int& ret = dp[y][x];
	if(ret != -1) return ret;

	return ret = triangle[y][x] + max(path2(y+1,x), path2(y+1,x+1));
}

int main(int argc, char **argv){
	 int C;
	 scanf("%d",&C);

	 while(C--){
		 scanf("%d",&N);

		 memset(triangle, 0, sizeof(triangle));
		 memset(dp, -1, sizeof(dp));

		 for(int y=0; y<N; y++){
				for(int x=0; x<y+1; x++){
					scanf("%d", &triangle[y][x]);
				}
		 }

		 int ans = path2(0,0);
		 printf("%d\n", ans);
	 }
}
