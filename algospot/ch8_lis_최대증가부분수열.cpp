#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

// solution #1 (TLE)
int lis(const vector<int>& A){
	// 기저 사례: A가 텅 비어 있을때
	if(A.empty()) return 0;   

	int ret = 0;

	for(int i=0; i<A.size(); i++){
		vector<int> B;
		for(int j=i+1; j<A.size(); j++){
			if(A[i] < A[j]) 
				B.push_back(A[j]);
		}
		ret = max(ret, 1 + lis(B));
	}

	return ret;
}


// solution #2 DP O(n^2)
int N;
int dp[500];
vector<int> A;

int lis2(int start) {
	int &ret = dp[start];
	if(ret != -1) return ret;
	
	// 항상 A[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	for(int next = start+1; next<N; next++){
		if(A[start] < A[next])
			ret = max(ret, lis2(next)+1);
	}

	return ret;
}

// solution #3 DP O(n^2)
// #2와 동일한 방법이나 시작 위치를 S[-1] = -inf로 고정한 방법 (정답은 lis3(-1)-1로 해줘야 함)
int lis3(int start) {
	int &ret = dp[start+1];
	if(ret != -1) return ret;
	
	// 항상 A[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	for(int next = start+1; next<N; next++){
		if(start == -1 || A[start] < A[next])
			ret = max(ret, lis3(next)+1);
	}

	return ret;
}

// solution #4 Binary Search O(nlogn)
// C[i] : 길이 i인 LIS 중에서 마지막 값의 최소값
int lis4(){
	vector<int> C;
	for(int i=0; i<A.size(); i++){
		if(i==0 || C.back() < A[i]) C.push_back(A[i]);
		else *lower_bound(C.begin(), C.end(), A[i]) = A[i];
	}
	return C.size();
}


int main(int argc, char **argv){
	int C;
	scanf("%d", &C);
	while(C--){
		scanf("%d", &N);

		memset(dp, -1, sizeof(dp));
		A.clear();

		for(int i=0; i<N; i++){
			int a;
			scanf("%d", &a);
			A.push_back(a);
		}

		// #1
		// int ans = lis(A);
		
		// #2
		// int ans=0;
		// for(int i=0; i<N; i++)  
		// 	ans = max(ans, lis2(i));

		// #3
		// int ans = lis3(-1) - 1;

		// #4
		int ans = lis4();

		printf("%d\n", ans);
	}
}

