#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 987654321;
// A[i]: 양자화해야 할 수열, 정렬한 상태
// pSum[]: A[]의 부분합을 저장한다. pSum[i]는 A[0] + ... + A[i]의 합
// pSqSum[]: A[] 제곱의 부분합을 저장한다. pSqSum[i]는 A[0]^2 + ... + A[i]^2의 합
int N, S;
int A[105], pSum[105], pSqSum[105];

// A를 정렬하고 각 부분합을 계산한다
void precalc(){
	sort(A, A+N);
	pSum[0] = A[0];
	pSqSum[0] = A[0]*A[0];

	for(int i=1; i<N; i++){
		pSum[i] = pSum[i-1] + A[i];
		pSqSum[i] = pSqSum[i-1] + A[i]*A[i];
	}
}

// A[lo] ... A[hi] 구간을 하나의 숫자로 표현할 때 최소 오차 합을 계산한다
int minError(int lo, int hi) {
	// 부분합을 이용해 A[lo] ~ A[hi]까지 합을 구한다
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
	
	// 평균을 반올림한 값으로 이 수들을 표현한다
	int m = int(0.5 + (double)sum / (hi-lo+1));

	// sum(A[i]-m)^2를 전개한 결과를 부분 합으로 표현
	int ret = sqSum - 2*m*sum + m*m*(hi-lo+1);
	return ret;
}

int dp[105][15];   // dp[from][parts] : from번째 이후 숫자들을 parts개 묶음으로 묶을 때 최소 오류 제곱 합

int quantize(int from, int parts) {
	// 기저 사례: 모든 숫자들을 다 양자화했을 때
	if(from == N) return 0;

	// 기저 사례: 숫자는 아직 남았는데 더 묶을 수 없을 때 아주 큰 값을 반환한다
	if(parts == 0) return INF;

	int& ret = dp[from][parts];
	if(ret != -1) return ret;

	ret = INF;

	// 조각의 길이를 변화시켜 가며 최소치를 찾는다
	for(int p=1; from+p <= N; p++){
		ret = min(ret, minError(from, from+p-1) + quantize(from+p, parts-1));
	}
	return ret;
}


int main(int argc, char **argv){
	int C;
	scanf("%d",&C);
	while(C--){
		scanf("%d %d", &N, &S);

		memset(dp, -1, sizeof(dp));

		for(int i=0; i<N; i++){
			scanf("%d", &A[i]);
		}

		precalc();
		
		int ret = quantize(0, S);
		printf("%d\n", ret);
	}
}
