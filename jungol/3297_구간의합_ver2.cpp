#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int LM = 100005;
const int TLM = 1<<21;
int N,Q;
ll tree[TLM];

void build(int u, int s, int e){
	if(s==e) {
		scanf("%lld\n", tree+u);
		return;
	}
	int lch=u*2, rch=lch+1, m=(s+e)/2;
	build(lch, s, m);
	build(rch, m+1, e);
	tree[u] = tree[lch] + tree[rch];
}

void update(int u, int s, int e, int idx, int nval){
	if(s==e){
		tree[u]=nval;
		return;
	}
	int lch=u*2, rch=lch+1, m=(s+e)/2;
	if(idx<=m) update(lch,s,  m,idx,nval);
	else       update(rch,m+1,e,idx,nval);
	tree[u] = tree[lch] + tree[rch];
}

ll query(int u, int s, int e, int qs, int qe){
	if(qe<s || e<qs) return 0;  
	if(qs<=s && e<=qe) return tree[u];

	int lch=u*2, rch=lch+1, m=(s+e)/2;
	ll lv = query(lch, s, m, qs, qe);
	ll rv = query(rch, m+1,e,qs,qe);
	return lv+rv;
}

int main(int argc, char **argv){
	//freopen("data/d1211.txt", "r", stdin);
	scanf("%d", &N);

	build(1,1,N);

	scanf("%d", &Q);
	int cmd,idx,nd,st,ed;
	for(int i=0;i<Q;i++){
		scanf("%d", &cmd);
		if(cmd == 1) {
			scanf("%d%d", &idx, &nd);
			update(1,1,N,idx,nd);
		}
		else {
			scanf("%d%d", &st,&ed);
			ll sum = query(1,1,N,st,ed);
			printf("%lld\n", sum);
		}
	}	
}