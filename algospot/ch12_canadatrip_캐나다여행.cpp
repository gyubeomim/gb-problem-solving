#include <bits/stdc++.h>
using namespace std;

const int LM=5005;
int N,K;
int L[LM], M[LM], G[LM];

// dist 지점까지 가면서 K개 이상의 표지판을 만날 수 있는가?
bool decision(int dist){
	int ret=0;
	for(int i=0;i<N;i++){
		// i번째 도시 표지판을 하나 이상 보게 되는가?
		if(dist >= L[i]-M[i])
			ret += (min(dist,L[i]) - (L[i]-M[i]))/G[i] + 1;
	}
	return ret >= K;
}

// k번째 표지판을 만나는 지점의 위치를 구한다
int optimize(){
	// 반복문 불변식 : !decision(lo) && decision(hi)
	int lo=-1, hi=8030001;
	while(lo+1<hi){
		int m = (lo+hi)/2;
		if(decision(m)) hi = m;
		else lo = m;
	}
	return hi;
}

int main(int argc, char **argv){
	// freopen("data/s_in_23451.txt", "r", stdin);
	int C; scanf("%d",&C);
	while(C--) {
			scanf("%d%d",&N,&K);
			for(int i=0;i<N;i++){
				scanf("%d%d%d",&L[i], &M[i], &G[i]);
			}
			int ans = optimize();
			printf("%d\n", ans);
	}
}
