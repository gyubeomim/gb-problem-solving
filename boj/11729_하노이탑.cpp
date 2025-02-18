#include <bits/stdc++.h>
using namespace std;

void hanoi(int from, int to, int n){
	if(n==1) { printf("%d %d\n",from,to); return; }

	int by = 6-from-to;

	hanoi(from, by, n-1);
	printf("%d %d\n", from,to);
	hanoi(by, to, n-1);
}

void hanoi2(int from, int by, int to, int n){
	if(n==1) { printf("%d %d\n", from, to); return; }

	hanoi2(from, to, by, n-1);
	printf("%d %d\n", from, to);
	hanoi2(by, from, to, n-1);
}

int main(int argc, char **argv){
	 int K; scanf("%d",&K);
	 printf("%d\n", (1<<K)-1);

	 hanoi(1, 3, K);
	 // hanoi2(1, 2, 3, K);
}
