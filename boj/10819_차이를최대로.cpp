#include <bits/stdc++.h>
using namespace std;

constexpr int LM=8;
int N;
int arr[LM];

int main(int argc, char **argv){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d", &arr[i]);
	}
	 
	sort(arr, arr+N);
	
	int maxval=-1;
	do{
		int val=0;
		for(int i=1; i<N;i++){
			val += abs(arr[i]-arr[i-1]);
		}
		if(val > maxval){
			maxval = val;
		}
	}while(next_permutation(arr, arr+N));

	printf("%d",maxval);

	return 0;
}
