#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

constexpr int LM = 10005;
int N,M,Q;

struct Player {
	int pid, total, cnt;
	double avg;

	void add(int s){
		total += s;
		cnt++;
	}
	void remove(int s){
		total -= s;
		cnt = max(0, cnt-1);
	}

	double getAvg() const {
		if(cnt == 0) return 0.;
		return (double)total / cnt;
	}
};

struct CmpSum{
	bool operator()(const Player *a, const Player *b) const{
		if(a->total == b->total) return a->pid < b->pid;
		return a->total < b->total;
	}	
};

struct CmpAvg{
		static int roundedAvg(const Player* p){
			if(p->cnt == 0) return 0;
			return (int)((ll)2 * p->total + p->cnt) / ((ll) 2*p->cnt);
		}
    bool operator()(const Player *a, const Player *b) const{
			int ra = roundedAvg(a);
			int rb = roundedAvg(b);

			if(ra != rb) return ra < rb;
			return a->pid < b->pid;
    }	
};


vector<Player> players;
set<Player*, CmpSum> S1;
set<Player*, CmpAvg> S2;
unordered_map<int, int> scout_score[LM]; 


int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d3838.txt", "r", stdin);
	#endif

	scanf("%d%d%d", &N,&M,&Q);

	players.resize(M+1);
	for(int i=1; i<=M; i++){
		players[i].pid = i;
		players[i].total = 0;
		players[i].cnt = 0;

		S1.insert(&players[i]);
		S2.insert(&players[i]);
	}

	while(Q--){
		string cmd; cin >> cmd;
		if(cmd == "EVAL"){
			int sid,pid,score; scanf("%d%d%d", &sid, &pid, &score);
			
			Player* p = &players[pid];
			auto sit1 = S1.find(p);
			auto sit2 = S2.find(p);
			if(sit1 != S1.end()) S1.erase(sit1);
			if(sit2 != S2.end()) S2.erase(sit2);

			auto mit = scout_score[sid].find(pid);
			if(mit != scout_score[sid].end()){
				p->remove(mit->Y);
			}

			scout_score[sid][pid] = score;
			p->add(score);

			S1.insert(p);
			S2.insert(p);
		}
		if(cmd == "CLEAR"){
			int sid; scanf("%d", &sid);
			for(auto e : scout_score[sid]){
				const int &pid = e.X;
				const int &score = e.Y;

				Player* p = &players[pid];
				auto sit1 = S1.find(p);
				auto sit2 = S2.find(p);
				if(sit1 != S1.end()) S1.erase(sit1);
				if(sit2 != S2.end()) S2.erase(sit2);

				p->remove(score);

				S1.insert(p);
				S2.insert(p);
			}
			scout_score[sid].clear();
		}
		if(cmd == "SUM"){
			int flag; scanf("%d", &flag);
			if(flag == 0){
				auto sit = S1.begin();
				printf("%d\n", (*sit)->pid);
			}
			if(flag == 1){
				auto sit = prev(S1.end());
				printf("%d\n", (*sit)->pid);
			}
		}
		if(cmd == "AVG"){
			int flag; scanf("%d", &flag);
			if(flag == 0){
				auto sit = S2.begin();
				printf("%d\n", (*sit)->pid);
			}
			if(flag == 1){
				auto sit = prev(S2.end());
				printf("%d\n", (*sit)->pid);
			}
		}
	}
}