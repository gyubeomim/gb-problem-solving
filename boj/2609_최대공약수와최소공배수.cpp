#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int getGCD(int a, int b) {
	int gcd=1;
	int div=2;
	while(true) {
		if(a % div == 0 && b % div == 0) {
			a /= div;
			b /= div;
			gcd*=div;
		}
		else 
			div++;

		if(div > a || div > b) break;
	}
	return gcd;
}

int getLCD(int a, int b) {
	int gcd=1;
	int div=2;
	while(true) {
		if(a % div == 0 && b % div == 0) {
			a /= div;
			b /= div;
			gcd*=div;
		}
		else 
			div++;

		if(div > a || div > b) break;
	}
	return gcd * a * b;
}

int main(int argc, char **argv){
	int n, m;
	scanf("%d %d", &n, &m);

	printf("%d %d", getGCD(n,m), getLCD(n,m));
}
