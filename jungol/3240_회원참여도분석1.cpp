#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int N,M;

struct Person{
	int id, freq;

	bool operator<(const Person& r) const{
		if(freq == r.freq) return id < r.id;
		return freq < r.freq;
	}
};

struct MaxCmp{
	bool operator()(const Person& a, const Person& b) const {
		if(a.freq == b.freq) return a.id > b.id;
		return a.freq > b.freq;
	}
};

set<Person> minS;
set<Person, MaxCmp> maxS;
int total_sum;

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d6666.txt", "r", stdin);
	#endif

	total_sum = 0;

	scanf("%d%d",&N,&M);
	for(int i=0; i<M; i++){
		int mode; scanf("%d", &mode);
		if(mode == 0){
			int id, freq; scanf("%d%d",&id, &freq);
			
			minS.insert({id, freq});
			maxS.insert({id, freq});
			total_sum += freq;
		}
		if(mode == 1){
			auto minit = minS.begin();
			if(minit == minS.end()) continue;

			total_sum -= minit->freq;

			printf("%d\n", minit->id);

			auto maxit = maxS.find({minit->id, minit->freq});

			if(minit != minS.end()) minS.erase(minit);
			if(maxit != maxS.end()) maxS.erase(maxit);
		}
		if(mode == 2){
			auto maxit = maxS.begin();
			if(maxit == maxS.end()) continue;

			total_sum -= maxit->freq;
			printf("%d\n", maxit->id);

			auto minit = minS.find({maxit->id, maxit->freq});

			if(minit != minS.end()) minS.erase(minit);
			if(maxit != maxS.end()) maxS.erase(maxit);
		}
		if(mode == 3){
			if(minS.size() > 1){
				printf("%d\n", total_sum - minS.begin()->freq - maxS.begin()->freq);
			}
			else if(minS.size() == 1){
				printf("%d\n", total_sum - minS.begin()->freq);
			}
			else{
				printf("%d\n", total_sum);
			}
		}
	}
}