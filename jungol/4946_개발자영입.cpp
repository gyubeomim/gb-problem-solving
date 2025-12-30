#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;


struct Devel{
	int id, salary, C,J,P;
	int total;

	Devel() {}

	Devel(int id, int salary, double C, double J, double P)
		:id(id), salary(salary), C(C), J(J), P(P) 
	{
		total = C+J+P;
	}

	void updateC(double v){ C = v; total = C+J+P; }
	void updateJ(double v){ J = v; total = C+J+P; }
	void updateP(double v){ P = v; total = C+J+P; }
};

struct Cmp1{
	bool operator()(const Devel* a, const Devel* b) const{
		if(a->salary == b->salary) return a->id < b->id;
		return a->salary < b->salary;
	}
};
struct Cmp2{
	bool operator()(const Devel* a, const Devel* b) const{
		if(a->total == b->total) return a->id > b->id; 
		return a->total > b->total;
	}
};

set<Devel*, Cmp1> S1;
set<Devel*, Cmp2> S2;
unordered_map<int, Devel*> hmap;

void removeDevel(Devel* d){
	S1.erase(d);
	S2.erase(d);
	hmap.erase(d->id);
	delete d;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d2828.txt", "r", stdin);
	#endif
	int Q; scanf("%d", &Q);
	while(Q--){
		string cmd; cin >> cmd;
		if(cmd == "register"){
			int pid, salary;
			double C,J,P;
			scanf("%d%d%lf%lf%lf", &pid, &salary, &C,&J,&P);

			Devel* d = new Devel{pid, salary, C,J,P};
			S1.insert(d);
			S2.insert(d);
			hmap[pid] = d;
		}
		if(cmd == "cancel"){
			int pid; scanf("%d", &pid);
			auto it = hmap.find(pid);
			if(it != hmap.end()){
				removeDevel(it->Y);
			}
		}
		if(cmd == "update"){
			int pid, flag;
			double x; 
			scanf("%d%d%lf", &pid, &flag, &x);
			auto it = hmap.find(pid);
			if(it != hmap.end()){
				auto sit1 = S1.find(it->Y);
				auto sit2 = S2.find(it->Y);
				S1.erase(sit1); S2.erase(sit2);

				if(flag == 0) it->Y->updateC(x);
				if(flag == 1) it->Y->updateJ(x);
				if(flag == 2) it->Y->updateP(x);

				S1.insert(it->Y); S2.insert(it->Y);
			}
		}
		if(cmd == "hire_min"){
			auto sit1 = S1.begin();

			Devel* d = *sit1;
			printf("%d\n", d->id);

			auto it = hmap.find(d->id);
			if(it != hmap.end()){
				removeDevel(it->Y);
			}

		}
		if(cmd == "hire_max"){
			auto sit2 = S2.begin();

			for(int i=0; i<3; i++){
				Devel* d = *sit2;
				printf("%d ", d->id);

				auto it = hmap.find(d->id);
				if(it != hmap.end()){
					auto next_sit2 = next(sit2);
					removeDevel(it->Y);
					sit2 = next_sit2;
				}
			}
			puts("");
		}
	}
}