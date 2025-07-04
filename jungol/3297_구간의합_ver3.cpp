#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int LM = 1<<20;
int N,Q,A[LM];
ll Bit[LM];

void update(int i, int v){
	for(;i<=N; i += i&-i) Bit[i] += v;
}

ll query(int i, ll sum=0){
	for(; i>0; i -= i&-i) sum += Bit[i];
	return sum;
}

int main(int argc, char **argv){
	//freopen("data/d1211.txt", "r", stdin);

	scanf("%d", &N);
	int i,cmd,idx,nd,st,ed;
	for(i=1; i<=N; i++){
		scanf("%d", &A[i]);
		update(i, A[i]);
	}
	scanf("%d", &Q);
	for(i=0; i<Q; i++){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d%d",&idx,&nd);
			update(idx, nd-A[idx]);
			A[idx]=nd;
		}else{
			scanf("%d%d",&st,&ed);
			ll ret = query(ed)-query(st-1);
			printf("%lld\n", ret);
		}
	}
}