#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

map<int, int> topu;

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1111.txt", "r", stdin);
	#endif

	int Q; scanf("%d",&Q);
	while(Q--){
		int cmd; scanf("%d", &cmd);
		if(cmd == 1){
			int worth; scanf("%d", &worth);
			topu[worth]++;
			printf("%d\n", topu[worth]);
		}
		if(cmd == 2){
			int worth; scanf("%d", &worth);
			auto it = topu.find(worth);
			if(it != topu.end()){
				topu[worth]--;
				printf("%d\n", topu[worth]);
				if(topu[worth] == 0) topu.erase(worth);
			}else{
				printf("-1\n");
			}
		}
		if(cmd == 3){
			int flag; scanf("%d", &flag);
			auto it = flag == 0 ? topu.begin() : --topu.end();
			int worth = it->X;
			topu[worth]--;
			printf("%d %d\n", worth, topu[worth]);
			if(topu[worth] == 0)  topu.erase(worth); 
		}
	}
}