#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM=5;

int N,M;
int arr[LM][LM];
bool visited[LM][LM];
int ans;

void solution() {
	for(int mask=0; mask < (1<<N*M) ; mask++) {
		int sum = 0;

		for(int r=0; r<N; r++){
			int tmp = 0;
			for(int c=0; c<M; c++){
				int k = r*M + c;
				if((mask & (1<<k)) == 0) tmp = tmp*10 + arr[r][c];
				else {
					sum += tmp;
					tmp = 0;
				}
			}
			sum += tmp;
		}

		for(int c=0; c<M; c++){
			int tmp = 0;
			for(int r=0; r<N; r++){
				int k = r*M + c;
				if((mask & (1<<k))) tmp = tmp*10 + arr[r][c];
				else {
					sum += tmp;
					tmp = 0;
				}
			}
			sum += tmp;
		}

		ans = max(ans, sum);
	}

	return; 
}

int main(int argc, char **argv){
	scanf("%d %d",&N,&M);

	char ch[LM];
	for(int r=0; r<N;r++){
		scanf("%s", ch);
		for(int c=0; c<M; c++){
			arr[r][c] = ch[c] - '0';
		}
	}

	solution();

	printf("%d",ans);
}
