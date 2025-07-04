#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
// digits: E의 자리수들을 정리한 것 
string E, digits;
int N,M;
int cache[1<<14][20][2]; 

// 과거 가격을 앞 자리부터 채워나가고 있다
// index: 이번에 채울 자리의 인덱스
// taken: 지금까지 사용한 자리수들의 집합
// mod: 지금까지 만든 가격의 M에 대한 나머지
// less: 지금까지 만든 가격이 이미 E보다 작으면 1 아니면 0
int price(int index, int taken, int mod, int less){
	// 기자 사례
	if(index == N) {
		return (less && mod == 0) ? 1 : 0;
	}

	// 메모이제이션
	int& ret = cache[taken][mod][less];
	if(ret != -1) return ret;
	ret = 0;
	for(int next = 0; next<N; next++){
		if((taken & (1<<next)) == 0){
			// 과겨 가격은 새 가격보다 항상 작아야 한다
			if(!less && E[index] < digits[next]) continue;
			// 같은 숫자는 한번만 선택한다
			if(next>0 
							&& digits[next-1] == digits[next] 
							&& (taken & (1<<next-1)) == 0) continue;

			int nextTaken = taken | (1<<next);
			int nextMod = (mod*10 + digits[next] - '0') % M;
			int nextLess = less || E[index] > digits[next];
			ret += price(index+1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
	}
	return ret;
}

#if 0  // 완전탐색 알고리즘
// e의 자리수로 만들 수 있는 숫자들을 모두 출력한다
// price: 지금까지 만든 가격
// taken: 각 자리수의 사용 여부
void generate(string price, bool taken[15]){
	// 기저 사례
	if(price.size() == N) {
		if(price < E) printf("%s\n", price.c_str());
		return ;
	}

	for(int i=0; i<N; i++){
		if(!taken[i] && (i==0 || digits[i-1] != digits[i] || taken[i-1])){
			taken[i] = true;
			generate(price + digits[i], taken);
			taken[i] = false;
		}
	}
}
#endif

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		// freopen("data/d1644.txt", "r", stdin);
	#endif
	int C; scanf("%d",&C);
	while(C--){
		cin >> E >> M;
		
		N = int(E.size());
		digits = E;
		sort(digits.begin(), digits.end());

		memset(cache, -1, sizeof(cache));
		int ans = price(0,0,0,0);
		printf("%d\n", ans);
	}
}