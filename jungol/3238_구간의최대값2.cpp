#include <bits/stdc++.h>
using namespace std;

enum { LM = 100005, MOD = 1 << 8, MASK = MOD - 1, INF = (int)2e9 };

int N,M;
int A[LM], B[LM];

void update(int idx, int newVal){
	int bn = idx/MOD; // 블록 넘버
	int st = bn*MOD, ed = min(st+MOD, N);
	A[idx] = B[bn] = newVal; // newVal로 초기값 채우기
	for(; st<ed; st++)       // bn 블록의 최대값 업데이트
		B[bn] = max(B[bn], A[st]);
}

int query(int s, int e){
	int ret = -INF;
	while(s<e && (s&MASK)) ret = max(ret, A[s++]); // 앞쪽 자투리에서 최대값 구하기
	while(s<e && (e&MASK)) ret = max(ret, A[--e]); // 뒤쪽 자투리 값들을 포함하여 최대값 업데이트
	for(; s<e; s+=MOD) ret = max(ret, B[s/MOD]);   // 블록 단위 대표값을 포함하여 최대값 업데이트
	return ret;
}

void process(){
	int cmd, k, val, s, e;
	for(int i=0; i<M; i++){
		scanf("%d",&cmd);
		if(cmd==1) {
			scanf("%d%d", &k, &val);
			update(k-1, val); // 0-base
		}
		else if(cmd == 2) {
			scanf("%d%d",&s,&e);
			int ret = query(s-1, e); // 0-base
			if(ret > -INF) printf("%d\n", ret);
		}
		else if(cmd == 3){
			scanf("%d",&k);
			update(k-1, -INF);
		}
	}
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1445.txt", "r", stdin);
	#endif
	scanf("%d%d",&N,&M);
	for(int i=0; i<=N; i++) {
		A[i] = B[i] = -INF;
	}

	process();
}