#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll POW(ll A, ll B, ll C){
	if(B==1) return A%C;
	ll half = POW(A, B/2, C);
	ll ret = (half*half)%C;
	if(B%2==0) return ret;
	else       return ret*A%C;
}

int main(int argc, char **argv){
	ll A,B,C;
	scanf("%lld%lld%lld",&A,&B,&C);
	printf("%lld", POW(A,B,C));
}
