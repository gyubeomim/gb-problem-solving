#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

/*
	n: 
	s:
	x: 
*/

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/1076a.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int n,s,x; scanf("%d%d%d", &n,&s,&x);

		vector<int> A(n);
		int sum = 0;
		for(int i=0;i<n;i++){
			scanf("%d", &A[i]);
			sum += A[i];
		}

		if(sum == s) printf("YES\n");
		else{
			if((s-sum) % x != 0) printf("NO\n");
			else {
				if(sum >= s) printf("NO\n");
				else{
					printf("YES\n");
				}
			}
		}
	}
}