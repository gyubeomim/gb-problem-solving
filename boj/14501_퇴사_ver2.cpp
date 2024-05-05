// 거꾸로 푼 예제
#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 18;

int main(int argc, char **argv){
	int i,j;
	int req_day[LM], pay[LM];
	int cost[LM] = {0};

	scanf("%d", &i);

	for(j = 1; j <= i; j++){
		scanf("%d %d", &req_day[j], &pay[j]);
	}

	for(j = i; j > 0; j--){
		if(req_day[j] > i-j+1) cost[j] = cost[j+1];
		else cost[j] = max(pay[j] + cost[j+req_day[j]], cost[j+1]);
	}

	printf("%d", cost[1]);
}
