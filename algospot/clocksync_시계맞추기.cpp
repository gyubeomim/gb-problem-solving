#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int INF = 9999;
constexpr int SWITCHES = 10;
constexpr int CLOCKS = 16;

// linked[i][j] = 'x' : i번 스위치와 j번 시계가 연결되어 있다
// linked[i][j] = '.' : i번 스위치가 j번 시계가 연결되어 있지 않다
const char linked[SWITCHES][CLOCKS+1] = {
	// 0123456789012345
	  "xxx.............",
	  "...x...x.x.x....",
		"....x.....x...xx",
		"x...xxxx........",
		"......xxx.x.x...",
		"x.x...........xx",
		"...x..........xx",
		"....xx.x......xx",
		".xxxxx..........",
		"...xxx...x...x.."};

// 모든 시계가 12시를 가리키고 있는지 확인한다
bool areAligned(const vector<int>& clocks) {
	for(int i=0; i<CLOCKS; i++){
		if(clocks[i] != 12) return false;
	}
	return true;
}

// s번 스위치를 누른다
void push(vector<int>& clocks, int s){
	for(int clock=0; clock<CLOCKS; ++clock){
		if(linked[s][clock] == 'x') {
			clocks[clock] += 3;
			if(clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

// clocks: 현재 시계들의 상태
// s: 이번에 누를 스위치 번호
// 가 주어질 때 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수를 반환한다
// 만약 불가능 하다면 INF 이상의 큰 수를 반환한다
int solve(vector<int>& clocks, int s){
	if(s == SWITCHES) return areAligned(clocks) ? 0 : INF;

	int ret = INF;
	for(int cnt=0; cnt<4; cnt++){
		ret = min(ret, cnt + solve(clocks, s+1));
		push(clocks, s);
	}

	return ret;
}

int main(int argc, char **argv){
	 int T;
	 scanf("%d", &T);

	 while(T--){
		 vector<int> clocks(CLOCKS);
		 for(int i=0; i<CLOCKS; i++){
			 scanf("%d", &clocks[i]);
		 }

		 int answer = solve(clocks, 0);

		 if(answer >= INF) printf("-1\n");
		 else printf("%d\n", answer);
	 }
}
