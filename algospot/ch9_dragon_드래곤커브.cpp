#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int MAX = (int)1e9+1;
const int LM = 55;
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

int N,P,L;
// length[i] = X나 Y를 i번 치환한 후 길이
int length[LM];

void precalc(){
	length[0]=1; 
	for(int i=1; i<=50; i++) 
		length[i] = min(MAX, length[i-1]*2 + 2);
}

// dragonCurve를 generations 진화시킨 결과에서 skip번째 문자를 반환한다
char expand(const string& dragonCurve, int generations, int skip){
	if(generations==0){
		assert(skip < dragonCurve.size());
		return dragonCurve[skip];
	}

	for(int i=0; i<dragonCurve.size(); i++){
		if(dragonCurve[i]=='X' || dragonCurve[i] == 'Y'){
			if(skip >= length[generations]){
				skip -= length[generations];
			}
			else if(dragonCurve[i] == 'X') {
				return expand(EXPAND_X, generations-1, skip);
			}
			else if(dragonCurve[i] == 'Y') {
				return expand(EXPAND_Y, generations-1, skip);
			} 
		}
		else if(skip > 0) skip--;
		else return dragonCurve[i];
	}
	return '#'; // 이 줄은 실행되지 않음
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	// freopen("data/d1565.txt", "r", stdin);
#endif

	precalc();

	int C; scanf("%d",&C);
	while(C--){
		scanf("%d%d%d",&N,&P,&L);
		for(int i=0;i<L;i++){
			printf("%c", expand("FX", N, P+i-1));
		} 
		puts("");
	}
}