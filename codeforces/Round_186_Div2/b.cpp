#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d2922.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int a, b; scanf("%d%d", &a,&b);

		int ans1 = 0;
		int a1=a, b1=b;
		int i = 0;

		while(1){
			a1 -= pow(2,i++); 
			if(a1 < 0) break;
			else ans1++;
			b1 -= pow(2,i++); 
			if(b1 < 0) break;
			else ans1++;
		}

		int ans2 = 0;
		int a2=a, b2=b;
		int j = 0;
		while(1){
			b2 -= pow(2,j++); 
			if(b2 < 0) break;
			else ans2++;
			a2 -= pow(2,j++); 
			if(a2 < 0) break;
			else ans2++;
		}

		// printf("ans1 %d\n", ans1);
		// printf("ans2 %d\n", ans2);

		int ans = max(ans1, ans2);

		printf("%d\n", ans);
		

	}
}