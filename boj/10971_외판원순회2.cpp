#include <bits/stdc++.h>
using namespace std;

constexpr int LM=10;
int N;
int arr[LM];
int W[LM][LM];

int main(int argc, char **argv){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		arr[i] = i;
		for(int j=0;j<N;j++){
			scanf("%d", &W[i][j]);
		}
	}

	int mincost=1e9;

	do{
		bool compute=true;
		int cost=0;
		for(int i=1; i<N; i++){
			int val = W[arr[i-1]][arr[i]];
			if(val == 0) {
				compute=false;
			}
			cost += val;
		}
		int val = W[arr[N-1]][arr[0]];
		if(val == 0) {
			compute=false;
		}
		cost += val;
		if(compute && mincost > cost) mincost = cost;

	} while(next_permutation(arr, arr+N));
	
	printf("%d", mincost);

	return 0;
}
