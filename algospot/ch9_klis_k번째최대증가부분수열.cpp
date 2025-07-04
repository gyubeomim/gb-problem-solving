#include <bits/stdc++.h>
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int MAX = (int)2e9 + 1;
const int LM = 505;

int N, K;
int cacheLen[LM], cacheCnt[LM], S[LM];

// S[start]에서 시작하는 증가부분수열 중 최대 길이를 반환한다
int lis(int start){
	// 메모이제이션
	int& ret = cacheLen[start+1];
	if(ret!=-1) return ret;
	// 항상 S[start]는 있기 때문에 길이는 최하 1
	ret = 1;
	for(int next=start+1; next<N; next++){
		if(start==-1 || S[start]<S[next])
			ret = max(ret, lis(next)+1);
	}
	return ret;
}

// S[start]에서 시작하는 최대증가부분수열의 수를 반환한다
int count(int start){
	// 기저 사례: LIS 길이가 1인 경우
	if(lis(start)==1) return 1;
	// 메모이제이션
	int& ret = cacheCnt[start+1];
	if(ret!=-1) return ret;
	ret = 0;
	for(int next=start+1; next<N; next++){
		if((start==-1 || S[start] < S[next]) && lis(start)==lis(next)+1){
			ret = min<ll>(MAX, (ll)ret + count(next));
		}
	}
	return ret;
}

// S[start]에서 시작하는 LIS 중 사전순으로 skip개 건너뛴 수열을 lis에 저장한다
void reconstruct(int start, int skip, vector<int>& L){
	// 1. S[start]는 항상 L에 포함된다
	if(start != -1) L.push_back(S[start]);

	// 2. 뒤에 올 수 있는 숫자들과 위치의 목록을 만든다
	vector<pii> followers; // (숫자, 위치)의 목록이 된다
	for(int next=start+1; next<N; next++){
		if((start==-1 || S[start]<S[next]) 
				&& lis(start) == lis(next)+1){
			followers.push_back( {S[next], next} );
		}
	}
	sort(followers.begin(), followers.end());

	// 3. k번째 lis의 다음 숫자를 찾는다
	for(int i=0; i<followers.size(); i++){
		// 이 숫자를 뒤에 이어서 만들 수 있는 lis의 개수를 본다
		int idx = followers[i].second;
		int cnt = count(idx);
		if(cnt <= skip) skip -= cnt;
		else {
			// 다음 숫자는 S[idx]이다
			reconstruct(idx, skip, L);
			break;
		}
	}
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	//freopen("data/d1316.txt", "r", stdin);
#endif
	int C; scanf("%d",&C);
	while(C--){
		scanf("%d%d", &N, &K);

		// printf("%d, %d\n", N, K);

		memset(cacheLen, -1, sizeof(cacheLen));
		memset(cacheCnt, -1, sizeof(cacheCnt));

		for(int i=0; i<N; i++){
			scanf("%d", &S[i]);
		}

		// puts("S is");
		// for(int i=0; i<N; i++){
		// 	printf("%d ", S[i]);
		// }puts("");
		
		vector<int> L;
		reconstruct(-1, K-1, L);
		printf("%lu\n", L.size());
		for(int i=0; i<L.size(); i++){
			printf("%d ", L[i]);
		}
		puts("");
	}
}