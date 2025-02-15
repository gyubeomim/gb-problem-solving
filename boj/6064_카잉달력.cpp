#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(a==0) return b;
	return gcd(b%a, a);
}

int lcm(int a, int b){
	return a / gcd(a,b) * b;
}

int solve(int m, int n, int x, int y){
	if(x==m) x=0;
	if(y==n) y=0;

	int l = lcm(m,n);

	for(int i=x; i<=l; i+=m) {   // lcm(n,m)/m 개의 수만 확인
		if(i==0) continue;
		if(i%n == y) return i;
	}
	return -1;
}

int main(int argc, char **argv){
	int N;
	scanf("%d",&N);

	while(N--){
		int m,n,x,y;
		scanf("%d%d%d%d",&m,&n,&x,&y);
		printf("%d\n", solve(m,n,x,y));
	}
	 
}
