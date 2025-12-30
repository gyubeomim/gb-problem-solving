#include <bits/stdc++.h>
using namespace std;

const int LM = 105;
int N;
int p[LM];
int rk[LM];

struct Data{
	int s,e,w;
	bool operator<(const Data& r) const {
		return w < r.w;
	}
} E[LM*LM];
int ecnt;

void input(){
	scanf("%d", &N);

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			int w;
			scanf("%d", &w);
			if(i<j) E[ecnt++] = {i,j,w};
		}
	}

	sort(E, E+ecnt);
}

int find(int x){
	if(p[x]==x) return x;
	return p[x] = find(p[x]);
}

void swap(int& a, int& b){ int c=a; a=b; b=c;}

bool Union(int a, int b){
	a=find(a), b=find(b);
	if(a==b) return 0;

	if(rk[a] < rk[b]) swap(a,b);
	p[b] = a;
	if(rk[a] == rk[b]) rk[a]++;
	return 1;
}

int kruskal(){
	int ret=0;
	for(int i=0;i<=N;i++) { p[i] = i; rk[i] = 0; }

	int cnt=0;
	for(int i=0; i<ecnt; i++){
		if(Union(E[i].s, E[i].e) == 0) continue;
		ret += E[i].w;
		cnt++;
		if(cnt == N-1) break;
	}

	return ret;
}


int main(int argc, char **argv){
	//freopen("data/s_in_3333.txt", "r", stdin);

	input();
	int ans = kruskal();
	printf("%d\n", ans);
}