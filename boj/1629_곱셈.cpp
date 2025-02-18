#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll A,B,C;

ll POW(ll a, ll b, ll m){
	if(b==1) return a%m;
	ll val = POW(a, b/2, m);
	val = val*val%m;
	if(b%2==0) return val;
	return val*a%m;
}

int main(int argc, char **argv){
	 scanf("%lld%lld%lld",&A,&B,&C);
	printf("%lld", POW(A,B,C));
}
