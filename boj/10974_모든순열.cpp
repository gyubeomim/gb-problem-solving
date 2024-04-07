#include <bits/stdc++.h>

#define rnt register int
using namespace std;

using pii = pair<int,int>;
using ll = long long;
constexpr int LM=8;
int N;
int arr[LM];

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		arr[i] = i+1;
	}
	
	do{
		for(int i=0;i<N;i++){
			printf("%d ", arr[i]);
		}printf("\n");
	} while(next_permutation(arr, arr+N));
	 

	return 0;
}
