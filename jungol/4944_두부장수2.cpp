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

int Q,cmd,worth,cnt,flag;
unordered_map<int,int> tmap;
priority_queue<pii> maxpq;
priority_queue<pii, vector<pii>, greater<pii>> minpq;

void add() {
	tmap[worth] += cnt;
	maxpq.push({ worth, tmap[worth]});
	minpq.push({ worth, tmap[worth]});
	printf("%d\n", tmap[worth]);
}

void remove() {
	auto it = tmap.find(worth);
	int ret = 0;
	if( it != tmap.end()) {
		it->Y -= min(cnt, it->Y);
		ret = it->Y;
		if(ret) {
			maxpq.push( {it->X, tmap[worth]});
			minpq.push( {it->X, tmap[worth]});
		}
	}
	printf("%d\n", ret);
}

template<class T>
void sell(T& pq) {
	ll sum = 0;
	while(cnt>0 && !pq.empty()) {
		auto tg = pq.top();
		while(!pq.empty() && tg == pq.top()) pq.pop();
		if(tmap[tg.X] != tg.Y) continue;

		int minCnt = min(cnt, tg.Y);
		sum += (ll)minCnt * tg.X;
		cnt -= minCnt, tg.Y -= minCnt, tmap[tg.X] -= minCnt;
		if(tg.Y > 0) {
			maxpq.push(tg); 
			minpq.push(tg);
		}
	}
	printf("%lld\n", sum);
}

int main(int argc, char **argv){
  scanf("%d",&Q);
  while(Q--){
	scanf("%d%d%d",&cmd,&worth,&cnt);
	if(cmd==3) flag = worth;
	if(cmd == 1) add();
	else if (cmd == 2) remove();
	else {
		if(flag == 0) sell(minpq);
		else sell(maxpq);
	}
  }
}