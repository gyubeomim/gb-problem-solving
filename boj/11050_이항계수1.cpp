#include <bits/stdc++.h>

int main(int argc, char **argv){
	 int N,K; 
	 scanf("%d%d",&N,&K);             // 5 2

	 int ret=1;
	 for(int i=1;i<=N;i++) ret*=i;    // 5!
	 for(int i=1;i<=K;i++) ret/=i;    // 3!
	 for(int i=1;i<=N-K;i++) ret/=i;  // 2!
	 printf("%d\n", ret);
}
