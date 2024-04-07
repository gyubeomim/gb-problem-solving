#include <bits/stdc++.h>
#define rnt register int
using namespace std;

constexpr int LM=10005;

int N;
int perm[LM];
int visited[LM];
int input[LM];

bool found=false;
bool next_ans=false;
bool exit_loop=false; 

void Permutation(int d){
	if(d == N+1) {
		if(next_ans) {
			for(int i=1;i<=N;i++) 
				printf("%d ", perm[i]);
			printf("\n");
			next_ans=false;
			exit_loop=true;
		}
		found=true;
		for(int i=1;i<=N;i++) {
			if(input[i-1] != perm[i]) {
				found =false;
				break;
			}
		}

		if(found) next_ans=true;

		return;
	}

	if(exit_loop) return;

	for(int i=1; i<=N; i++){
		if(visited[i]) continue;

		visited[i] = true;
		perm[d] = i;
		Permutation(d+1);
		visited[i] = false;
	}
}

int main(int argc, char **argv){
	scanf("%d", &N);
	for(int i=0;i<N;i++) {
		int val;
		scanf("%d", &val);
		input[i] = val;
	}

	bool check_last=true;
	for(int i=N;i>0;i--) {
		if(i != input[N-i]) { 
			check_last=false; 
			break;
		}
	}
	if(check_last) printf("-1\n");
	else Permutation(1);

	return 0;
}

