#include <bits/stdc++.h>
using ull=unsigned long long;
using namespace std;

ull N;

ull bisearch(ull l, ull r, ull tg){
	ull m;
	ull ans=tg;
	while(l <= r){
		m = (l+r)/2;
		if(m <= tg/m) {
			ans = m;
			l = m+1;
		}
		else r = m-1;
	}
	return ans;
}

int main(int argc, char **argv){
	scanf("%llu", &N);
	ull ans = bisearch(1, N, N);
	printf("%llu\n", ans);
}