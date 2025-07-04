#include <bits/stdc++.h>
using namespace std;

const int LM = 15;
int K;
string word[LM];
int cache[LM][1<<LM], overlap[LM][LM];

// O(k * 2^k)의 부분문제에 대한 답을 O(k) 시간을 들여 계산한다
// --> O(k^2 * 2^k)
int restore(int last, int used){
	// 기저 사례
	if(used == (1<<K)-1) return 0;
	
	int& ret = cache[last][used];
	if(ret!=-1)return ret;
	ret =0;
	for(int i=0; i<K; i++){
		if((used & (1<<i)) == 0) {
			// restore(last,used) = max(overlap(last,next) + restore(next, used {next}))
			int cand = overlap[last][i] + restore(i, used + (1<<i));
			ret = max(ret, cand);
		}
	}
	return ret;
}

// 처음 호출 시 last는 recover()가 최대값을 반환한 시작 단어로
// used는 1<<last로 둔다
string reconstruct(int last, int used){
	// 기저 사례 
	if(used == (1<<K)-1) return "";

	// 다음에 올 문자열 조각을 찾는다
	for(int i=0; i<K; i++){
		// next가 이미 사용되었으면 제외
		if(used & (1<<i)) continue;

		// i를 사용했을 경우 답이 최적해와 같다면 i를 사용한다
		int ifUsed = restore(i, used+(1<<i)) + overlap[last][i];
		if(restore(last, used) == ifUsed){
			return (word[i].substr(overlap[last][i]) + reconstruct(i, used+(1<<i)));
		}
	}
	return "****oops****";
}

int getOverlap(string& s1, string& s2){
	int len=min(s1.size(),s2.size());
	while(len>=0){
		if(s1.substr(s1.size()-len) == s2.substr(0, len)) {
			return len;
		}
		len--;
	}
	return 0;
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	// freopen("data/d6211.txt", "r", stdin);
#endif
	// int C; scanf("%d",&C);
	int C; cin >> C;
	while(C--) {
		// scanf("%d",&K);
		cin >> K;

		memset(cache,-1,sizeof(cache));
		memset(overlap,-1,sizeof(overlap));

		for(int i=0; i<K; i++) cin >> word[i];

		while(1){
			bool removed=false;
			for(int i=0; i<K && !removed; i++){
				for(int j=0; j<K; j++) {
					if(i != j && word[i].find(word[j]) != -1) {
						word[j] = word[K-1];
						K--;
						removed = true;
					}
				}
			}
			if(!removed) break;
		}
		word[K] = "";

		for(int i=0; i<=K; i++){
			for(int j=0; j<=K; j++){
				overlap[i][j] = getOverlap(word[i], word[j]);
			}
		}
		string ans = reconstruct(K, 0);
		printf("%s\n", ans.c_str());
	}
}