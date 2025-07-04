#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int LM = 1<<20;
const int MOD = 1<<10;
const int MASK = MOD-1;
int N,Q,A[LM];
ll B[LM];

void update(int idx, int nd){
	int delta = nd - A[idx];
	A[idx] = nd;
	B[idx/MOD] += delta;
}

ll query(int s, int e){
	ll sum =0;
	while(s<e && (s&MASK)) sum += A[s++]; // 앞쪽 자투리의 합
	while(s<e && (e&MASK)) sum += A[--e]; // 뒤쪽 자투리의 합
	for(; s<e; s+=MOD) sum += B[s/MOD];
	return sum;
}

int main(int argc, char **argv) {
  // freopen("data/d1211.txt", "r", stdin);
  scanf("%d", &N);
  for (int i = 0; i < N; i++) { 
		scanf("%d", A+i);
		B[i / MOD] += A[i];  // 블록(MOD) 단위 구간합
	}

  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    int cmd;
    scanf("%d", &cmd);
    if (cmd == 1) {
      int idx, nd;
      scanf("%d%d", &idx, &nd);
      update(idx - 1, nd);
    } else {
      int st, ed;
      scanf("%d%d", &st, &ed);
      ll ret = query(st - 1, ed);
      printf("%lld\n", ret);
    }
  }
}