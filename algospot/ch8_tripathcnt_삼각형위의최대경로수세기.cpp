#include <bits/stdc++.h>
using namespace std;

int N;
int triangle[105][105];

int dp1[105][105];  // for path2
int dp2[105][105];  // for count

int path2(int y, int x) {
	if(y == N-1) return triangle[y][x];

	int& ret = dp1[y][x];
	if(ret != -1) return ret;

	return ret = triangle[y][x] + max(path2(y+1, x), path2(y+1, x+1));
}

// (y,x)에서 시작해서 맨 아래줄까지 내려가는 경로 중 최대 경로의 개수 반환
int count(int y, int x){
	if(y==N-1) return 1;   // 기저 사례: 맨 아래줄에 도달한 경우

	int& ret = dp2[y][x];
	if(ret!=-1) return ret;

	ret = 0;
	if(path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x+1);
	if(path2(y+1, x+1) <= path2(y+1, x)) ret += count(y+1, x);

	return ret;
}

int main(int argc, char **argv){
	int C; scanf("%d", &C);
	while(C--){
		scanf("%d", &N);

		memset(triangle, 0, sizeof(triangle));
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));

		for(int y=0; y<N; y++){
			for(int x=0; x<y+1; x++){
				scanf("%d", &triangle[y][x]);
			}
		}

		int ans = count(0,0);
		printf("%d\n", ans);
	}
}
