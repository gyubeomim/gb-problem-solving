// 일반적인 DFS로 푼 예제
#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 15;
struct Data{
	int req_day; 
	int payment;
};

int N;
int answer=0;
Data arr[LM];

void DFS(int day, int income) {
	answer = max(answer, income);

	for(int i=day; i<N; i++){
		int next_day = i + arr[i].req_day;
		if(next_day > N) continue;
		DFS(next_day, income + arr[i].payment);
	}
}


int main(int argc, char **argv){
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d %d", &arr[i].req_day, &arr[i].payment);
	}

	DFS(0,0);
	printf("%d", answer);
}
