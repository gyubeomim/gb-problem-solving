#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

vector<int> h;
int N;

// solution #1
int bruteForce(const vector<int>& h){
	int ret=0;

	for(int l=0; l<N; l++){
		int minH = h[l];
		for(int r=l; r<N; r++){
			minH = std::min(minH, h[r]);
			ret = std::max(ret, (r-l+1)*minH);
		}
	}
	return ret;
}

// solution #2
// h[l,r]: 구간에서 찾아낼 수 있는 가장 큰 사각형의 넓이를 반환
int divideAndConquer(int l, int r){
	// 기저 사례: 판자가 하나 밖에 없는 경우
	if(l == r) return h[l];
	
	// [l, m], [m+1, r] 두 구간으로 문제를 분할한다
	int m = (l+r)/2;
	
	// 분할한 문제를 각개격파
	int ret = max(divideAndConquer(l, m), divideAndConquer(m+1, r));
	
	// 부분문제3: 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다
	int lo = m, hi = m+1;
	int height = min(h[lo], h[hi]);
	
	// [m, m+1]만 포함하는 너비 2인 사각형을 고려한다
	ret = max(ret, height*2);
	
	// 사각형이 입력 전체를 덮을 때까지 확장해 나간다
	while(l < lo || hi < r) {
		// 항상 높이가 더 높은 쪽으로 확장한다
		if(hi < r && (lo == l || h[lo-1] < h[hi+1])){
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		// 확장한 후 사각형 넓이
		ret = max(ret, height * (hi-lo+1));
	}
	return ret;
}

int main(int argc, char **argv){
	int C;
	scanf("%d",&C);

	while(C--){
		h.clear();

		scanf("%d",&N);

		for(int i=0; i<N; i++){
			int a;
			scanf("%d", &a);
			h.push_back(a);
		}

		// int ret = bruteForce(h);
		int ret = divideAndConquer(0, N-1);
		printf("%d\n", ret);
	}
}
