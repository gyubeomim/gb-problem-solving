#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int N;

int main(int argc, char **argv){
	scanf("%d",&N);
		
	int div=2;
	while(N > 1) {
		if(N % div == 0) {
			N /= div;
			printf("%d\n", div);
		} 
		else{
			div++;
		}
	}
}
