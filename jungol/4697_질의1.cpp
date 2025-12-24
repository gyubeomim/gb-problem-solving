#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

struct Data{
	int id, val;
	bool operator<(const Data& r) const {
		if(val == r.val) return id < r.id;
		return val < r.val;
	}
	bool operator>(const Data& r) const {
		if(val == r.val) return id > r.id;
		return val > r.val;
	}
};

priority_queue<Data> maxpq;
priority_queue<Data, vector<Data>, greater<Data>> minpq;
unordered_map<int, int> hmap;

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/Query1.txt", "r", stdin);
	#endif
	int Q; scanf("%d",&Q);

	for(int i=0;i<Q;i++){
		int cmd=0;
		scanf("%d", &cmd);

		if(cmd == 1){
			int id,val;
			scanf("%d%d",&id, &val);
			hmap[id] = val;
			maxpq.push({id, val});
			minpq.push({id, val});
		}
		else if(cmd == 2){
			int id; scanf("%d", &id);
			// auto it = hmap.find(id);
			// if(it != hmap.end()){
			// 	hmap.erase(it);
			// 	// printf("CMD2 : Delete %d\n", id);
			// }
			hmap.erase(id);
		}
		else if(cmd == 3){
			while(!minpq.empty()) {
				Data top = minpq.top();
				auto it = hmap.find(top.id);
				if(it != hmap.end() && it->Y == top.val) { break; }
				minpq.pop(); 
			}

			if(!minpq.empty()){
				printf("%d\n", minpq.top().id);
			} else{
				printf("-1\n");
			}
		}
		else if(cmd == 4){
			while(!maxpq.empty()) {
				Data top = maxpq.top();
				auto it = hmap.find(top.id);
				if(it != hmap.end() && it->Y == top.val) { break; }
				maxpq.pop(); 
			}

			if(!maxpq.empty()){
				printf("%d\n", maxpq.top().id);
			} else{
				printf("-1\n");
			}
		}
	}
}