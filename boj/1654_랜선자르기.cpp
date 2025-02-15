#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int LM = 10005;

int N,K;
int A[LM];

// Parametric search
bool solve(ll x){
	ll cur = 0;
	for(int i=0;i<K;i++) 
		cur += A[i]/x;
	return cur >= N;
}

int main(int argc, char **argv){
	scanf("%d %d",&K,&N);
	for(int i=0;i<K;i++) 
		scanf("%d", &A[i]);

	ll st = 1;
	ll en = 0x7fffffff;  // 2^31 - 1

	while(st < en) {
		ll m = (st+en+1)/2;
		if(solve(m)) st = m;
		else en = m-1;
	}

	printf("%lld\n", st);
}
