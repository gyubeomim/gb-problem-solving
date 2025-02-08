#include <bits/stdc++.h>
using ll = long long;

// 시간복잡도 O(log n)
ll fastSum(int n){
	if(n==1) return 1;

	if(n%2 == 1) 
		return fastSum(n-1) + n;
	else 
		return 2*fastSum(n/2) + (n/2)*(n/2);
}

int main(int argc, char **argv){
	printf("%lld\n", fastSum(9651));   // 46575726
}
