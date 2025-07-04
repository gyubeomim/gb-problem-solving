#include <bits/stdc++.h>
using namespace std;

const int LM = 205;
const int INF = 0x3f3f3f3f;
int bino[LM][LM];
int N,M,K;

// #4
// n개의 -, m개의 o로 구성된 신호 중 skip개를 건너뛰고 만들어지는 신호를 반환한다
string kth(int n, int m, int k){
	// n==0인 경우 나머지 부분은 전부 o일 수 밖에 없다
	if(n==0) return string(m, 'o');

	if(k < bino[n+m-1][n-1])
		return "-" + kth(n-1, m, k);

	return "o" + kth(n, m-1, k-bino[n+m-1][n-1]);
}


// #3
// 필요한 모든 이항계수를 미리 계산해 둔다 
// O(nm)
void calcBino(){
	memset(bino, 0, sizeof(bino));
	for(int i=0; i<LM; i++){
		bino[i][0] = bino[i][i] = 1;
		for(int j=1; j<i; j++) 
			bino[i][j] = min(INF, bino[i-1][j-1] + bino[i-1][j]);
	}
}

// skip개를 건너뛰고 출력한다
void generate3(int n, int m, string s){
	if(K < 0) return;
	if(n==0 && m==0) {
		if(K==0) printf("%s\n", s.c_str());
		--K;
		return;
	}
	if(bino[n+m][n] <= K) {
		K -= bino[n+m][n];
		return;
	}
	if(n>0) generate3(n-1, m, s + "-");
	if(m>0) generate3(n, m-1, s + "o");
}

// #2
#if 0
void generate2(int n, int m, string s){
	// 기저 사례 : K < 0
	if(K < 0) return;
	if(n==0 && m==0) {
		if(K==0) printf("%s\n", s.c_str());
		--K;
		return;
	}
	if(n>0) generate2(n-1, m, s + "-");
	if(m>0) generate2(n, m-1, s + "o");
}
#endif

// #1
#if 0
// s: 지금까지 만든 신호
// n: 더 필요한 -의 개수
// m: 더 필요한 o의 개수
void generate(int n, int m, string s){
	// 기저사례 : n=m=0
	if(n==0 && m==0) {
		printf("%s\n", s.c_str()); return;
	}
	if(n>0) generate(n-1, m, s + "-");
	if(m>0) generate(n, m-1, s + "o");
}
#endif



int main(int argc, char **argv){
	// freopen("data/d1231.txt", "r", stdin);
	int C; scanf("%d",&C);

	while(C--){
		scanf("%d%d%d", &N, &M, &K);
		K -= 1;
		calcBino();

		// string ans; 
		// generate3(N, M, ans);

		string ans = kth(N, M, K);
		printf("%s\n", ans.c_str());
	}
}