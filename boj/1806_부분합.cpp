#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 100005;
constexpr int INF = 0x7fffffff;

int A[LM];
int N, S;
int tot;

int main(int argc, char **argv){
	 scanf("%d%d",&N,&S);
	
	 for(int i=0; i<N; i++){
		 scanf("%d", &A[i]);
	 }

	 int ans = INF;

	 // Two pointers
	 tot = A[0];
	 int en = 0;
	 for(int st=0; st<N; st++){
		 while(en<N && tot <S) {
			 en++;
			 if(en!=N) tot += A[en];
		 }
		 if(en==N) break;  
		 ans = min(ans, en-st+1);
		 tot -= A[st];
	 }

	 if(ans == INF) ans=0;
	 printf("%d\n", ans);
}
