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

int Q;
int cmd, worth, cnt, flag;
map<int,int> tmap;

void add(){
	tmap[worth] += cnt;
	printf("%d\n", tmap[worth]);
}

void remove(){
	auto it = tmap.find(worth);
	int ret = 0;
	if(it != tmap.end()){
		it->Y -= min(cnt, it->Y);
		ret = it->Y;
		if(it->Y == 0) tmap.erase(it);
	}
	printf("%d\n", ret);
}

void sell() {
	if(tmap.empty()) puts("0");
	else {
		ll sum=0;
		while(cnt>0 && !tmap.empty()) {
			auto it = tmap.begin();
			if(flag == 1) it = prev(tmap.end());
			int minCnt = min(cnt, it->Y);
			sum += (ll)minCnt * it->X;
			cnt -= minCnt;
			it->Y -= minCnt;
			if(it->Y == 0) tmap.erase(it);
		}
		printf("%lld\n",sum);
	}
}

int main(int argc, char **argv){
  scanf("%d",&Q);
  while(Q--){
	scanf("%d%d%d",&cmd,&worth,&cnt);
	if(cmd==3) flag = worth;
	if(cmd==1) add();
	else if(cmd==2) remove();
	else sell();
  }
}