#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int INF = 987654321;
string N;

int classify(int a, int b){
	string M = N.substr(a, b-a+1);

	// 첫 글자만으로 이루어진 문자열과 같으면 난이도는 1
	if(M == string(M.size(), M[0])) return 1;

	// 등차수열인지 검사한다
	bool progressive = true;
	for(int i=0; i<M.size()-1; i++){
		if(M[i+1] - M[i] != M[1] - M[0]) 
			progressive = false;
	}

	// 등차수열이고 공차가 1혹은 -1이면 난이도는 2
	if(progressive && abs(M[1] - M[0]) == 1) return 2;

	// 두 수가 번갈아 등장하는지 확인한다
	bool alternating = true;
	for(int i=0; i<M.size(); i++){
		if(M[i] != M[i%2])
			alternating = false;
	}
	if(alternating) return 4;   // 두 수가 번갈아 등장하면 난이도는 4
	if(progressive) return 5;   // 공차가 1이 아닌 등차 수열의 난이도는 5

	return 10;                  // 이 외는 모두 난이도 10
}

int dp[10005];

int memorize(int begin){
	if(begin == N.size()) return 0;

	int& ret = dp[begin];
	if(ret != -1) return ret;

	ret = INF;
	for(int L=3; L<=5; L++){
		if(begin + L <= N.size()) 
			ret = min(ret, memorize(begin+L) + classify(begin, begin+L-1));
	}

	return ret;
}

int main(int argc, char **argv){
	int C;
	scanf("%d",&C);
	while(C--){
		cin >> N;

		memset(dp, -1, sizeof(dp));

		int ans = memorize(0);
		printf("%d\n", ans);
	}
}
