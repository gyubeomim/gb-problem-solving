#include <bits/stdc++.h>

int N, M;
bool taken[10];    // taken[i] = i번째 학생이 짝을 이미 찾았으면 true 아니면 false
bool areFriends[10][10];

int countPairings(bool taken[10]){
	int firstFree = -1;
	for(int i=0; i<N; i++) if(!taken[i]) { firstFree = i; break; }
	
	if(firstFree == -1) return 1;

	int ret = 0;
	for(int pairWith = firstFree+1; pairWith < N; ++pairWith) {
		if(!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main(int argc, char **argv){
	int T;
	scanf("%d", &T);
	
	while(T--){
		scanf("%d %d", &N, &M);

		memset(taken, 0, sizeof(taken));
		memset(areFriends, 0, sizeof(areFriends));

		for(int i=0; i<M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		
		printf("%d\n", countPairings(taken));
	}
}
