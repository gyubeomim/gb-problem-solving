#include <bits/stdc++.h>
using namespace std;

constexpr int LM=10005;

int num[LM] = {0};
int N;

int main(int argc, char **argv){
	scanf("%d",&N);

	for(int i=0;i<N;i++)
		scanf("%d", &num[i]);

	if(next_permutation(num, num+N))
		for(int i=0;i<N;i++)
			printf("%d ", num[i]);
	else
		printf("-1\n");


	return 0;
}

