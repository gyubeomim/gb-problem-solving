#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll L = 2000000000;

// games 게임 중 won번 승리했을 때 승률
int Ratio(ll games, ll won) {
	return (won*100)/games;
}

int needs(ll games, ll won){
	// 불가능한 경우를 미리 걸러낸다
	if(Ratio(games, won) == Ratio(games+L, won+L)) return -1;

	ll lo=0, hi=L;
	while(lo+1 < hi) {
		ll m = (lo+hi)/2;
		if(Ratio(games, won) == Ratio(games+m, won+m)) lo = m;
		else hi = m;
	}
	return hi;
}

int main(int argc, char **argv){
	// freopen("data/s_in_1239.txt", "r", stdin);
	int C; scanf("%d",&C);
	while(C--) {
		ll a,b;
		scanf("%lld %lld",&a,&b);
		int ans = needs(a,b);
		printf("%d\n", ans);
	}
}
