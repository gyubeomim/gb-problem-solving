#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 1005;
int N,M;
double dp[LM][2*LM+1];

// 달팽이가 days일 동안 climbed 미터를 기어올라 왔다고 할 때
// M일 전까지 N 미터를 기어올라갈 수 있는 확률
double climb2(int days, int climbed){
	// 기저 사례: M일이 모두 지난 경우
	if(days == M) return climbed >= N ? 1 : 0;

	double& ret = dp[days][climbed];
	if(ret != -1) return ret;

	return ret = 0.25*climb2(days+1, climbed+1) + 0.75*climb2(days+1, climbed+2);
}

int main(int argc, char **argv){
	 int C; scanf("%d",&C);
	 while(C--) {
	 		scanf("%d %d",&N,&M);
			
			std::fill_n(&dp[0][0], LM*(2*LM+1), -1.0);

			double ans = climb2(0, 0);
			printf("%.10lf\n", ans);
	 }
}
