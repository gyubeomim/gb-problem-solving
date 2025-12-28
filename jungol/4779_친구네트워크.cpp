#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 200005;

int idcnt;
unordered_map<string, int> hmap;

int p[LM];
int rk[LM];
int sum[LM];

inline int find(int x){
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}

inline void swap(int &a, int &b) { int c=a; a=b; b=c;}

inline void Union(int a, int b){
	a = find(a); b = find(b);
	if(a == b) {
		printf("%d\n", sum[a]);
		return;
	}

	if(rk[a] < rk[b]) swap(a,b);
	p[b] = a;
	sum[a] += sum[b];
	if(rk[a] == rk[b]) rk[a]++;

	printf("%d\n", sum[a]);
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d4779.txt", "r", stdin);
#endif
	int Q; scanf("%d", &Q);
	while(Q--) {
		idcnt=0;
		hmap.clear();

		int E; scanf("%d\n", &E);

		for(int i=0; i<2*E; i++){
			p[i] = i;
			rk[i] = 0;
			sum[i] = 1;
		}

		for(int i=0; i<E; i++){
			string s1,s2; cin>>s1 >> s2;
			
			if(hmap.find(s1) == hmap.end()) hmap[s1] = idcnt++;
			if(hmap.find(s2) == hmap.end()) hmap[s2] = idcnt++; 

			Union(hmap[s1], hmap[s2]);
		}
	}
}