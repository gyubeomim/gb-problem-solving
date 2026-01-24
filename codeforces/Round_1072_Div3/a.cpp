#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

/*
	4 = [2] [2] : 0
	5 = [2] [3] : 1
	6 = [3] [3] : 0
	7 = [3] [2] [2] : 1 
	8 = [2] [2] [2] [2] : 0 (O)
	9 = [2] [2] [2] [3] : 1 (O)

*/

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d1072a.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		if(N==2)      printf("2\n");
		else if(N==3) printf("3\n");
		else if(N%2 == 0) printf("0\n");
		else if(N%2 == 1) printf("1\n");
	}
}